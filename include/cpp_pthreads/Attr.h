/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cpp-pthreads.
 *
 *  cpp-pthreads is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cpp-pthreads is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cpp-pthreads.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  @file   include/cpp-pthreads/Attr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  Attr<Base> template and support classes
 */

#ifndef CPP_PTHREADS_ATTR_H_
#define CPP_PTHREADS_ATTR_H_


namespace pthreads
{

// forward declarations
template <class Base >              class  Attr;
template <class Base, typename T>   struct Assignment;
template <class Base, typename T>   struct Access;
template <class Base, typename T>   struct Delegate;

/// template used to resolve the pthreads_xxx_t object corresponding to the
/// Attr<Base> object
template <class Base>               struct AttrType;




/// assignment delegate, an object which can assign an attribute value to an
/// attribute object
template <class Base, typename T>
struct Assignment
{
    T  m_value; ///< storage for the value to be assigned

    /// constructs an assignment object from a value
    Assignment( const T& value ):
        m_value(value)
    {}

    /// sets the attribute value of attr to the value stored in this object
    int set( Attr<Base>& attr ) const;
};




/// access delegate, an object which can access an attribute value of an
/// attribute object
template <class Base, typename T>
struct Access
{
    Access(){}

    /// retrieves the attribute value of attr corresponding to @p T
    int get( Attr<Base>& attr, T& value ) const;
};


/// since a template parameter cannot be a friend (until C++-11) this template
/// simply allows us to work around that limitation
template <class T>
struct Friendly
{
    typedef T type;
};




/// Attributes object for type @p Base
/**
 *  For example, Attr<Thread> is the cpp-pthreads object wrapping
 *  pthread_attr_t
 */
template <class Base>
class Attr
{
    private:
        /// the wrapped pthreads_XXXattr_t object
        typename AttrType<Base>::type m_data;

    public:
        template <class Base2, typename T> friend class Assignment;
        template <class Base2, typename T> friend class Access;
        template <class Base2, typename T> friend class Delegate;
        friend class Friendly<Base>::type;

        /// initialize the attribute object
        int init();

        /// destroy the attribute object
        int destroy();

        /// safe assignment of an attribute by value, use only when type is
        /// implied
        /**
         *  @tparam T       the type of the value to set, see note
         *  @param  value   The value to set
         *
         *  @return result of pthread_[BASE]attr_set[T]()
         *  @note   the field to set is implied by the type parameter @p T.
         *          For enumerators this is implied natively. For values which
         *          are built-in data types, use the constructor for the
         *          actual data type. For instance to set the guardsize of an
         *          Attr<Thread> to a value 100 use set( GuardSize(100) )
         */
        template <typename T>
        int set( const T& value)
        {
            Assignment<Base,T> assignment(value);
            return assignment.set(*this);
        }

        /// safe value retrieval, sets @p value to the value stored in the
        /// attribute object
        /**
         *  @tparam T       the type of the value to get, see note
         *  @param  value   where to store the value when retrieved
         *  @return result of pthread_[BASE]attr_get[T]()
         *
         *  @note   the field to get is implied by the type parameter @p T.
         *          For enumerators this is implied natively. For values which
         *          are built-in data types, use the data type specific to
         *          the field. For instance to get the guardsize of an
         *          Attr<Thread> object use the following:
         *
         *  @code
     Attr<Thread>   attr;
     GuardSize      gs;
     int result = attr.get( gs );
         @endcode
         */
        template <typename T>
        int get( T& value )
        {
            Access<Base,T> access;
            return access.get( *this, value );
        }

        /// safe value retrieval, sets @p value to the value stored in the
        /// attribute object
        /**
         *  @tparam T       the type of the value to get, see note
         *  @tparam U       the type of the result object to set
         *  @param  access  object of type Access<Base,T> which retrieves the
         *                  correct attribute value
         *  @param  value   the value to retrieve
         *  @return result of pthread_[BASE]attr_get[T]()
         *
         *  @note   the field to get is implied by the type parameter @p T.
         *          In order to tell the compiler which object you are trying
         *          to retrieve, use one of the statically defined
         *          Access<Base,T> object. For instance to get the guardsize of
         *          an Attr<Thread> object as an in use the following:
         *
         *  @code
     Attr<Thread>   attr;
     int            gs;
     int result = attr.get( GUARD_SIZE, gs );
         @endcode
         */
        template <typename T, typename U>
        int get( const Access<Base,T>& access, U& value )
        {
            T tVal;
            int return_val = access.get( *this, tVal );
            value = tVal;
            return return_val;
        }

        /// stream assignment, unsafe, ignores error values returned
        /**
         *  Usage
         *  @code
    Attr<Thread> attr;

    attr << JOINABLE
         << Stack(0,100)
         << DETACHED
         << EXPLICIT
         << GuardSize(100)
         << SYSTEM;
         @endcode
         */
        template <typename T>
        Attr<Base>& operator << ( const T& value )
        {
            Assignment<Base,T> assignment(value);
            assignment.set(*this);
            return *this;
        }

        /// map operator, unsafe assignment and retrieval, ignores error values
        /// returned
        /**
         *  Usage:
         *  @code
    Attr<Thread> attr;

    // set by map operator
    attr[DETACH_STATE] = DETACHED;
    attr[INHERIT_SCHED]= INHERIT;

    // retrieve by map operator
    DetachState  ds = attr[DETACH_STATE];
    InheritSched is = attr[INHERIT_SCHED];
         @endcode
         */
        template <typename T>
        Delegate<Base,T> operator[]( const Access<Base,T>& access )
        {
            return Delegate<Base,T>(*this);
        }
};


/// two-way delegate, may assign or retrieve (unsafely) an attribute value
/// of an attribute object
/**
 *  @note   This is an intermediate object returned by the map operator for
 *          an attribute class. There isn't any reason for you to use this
 *          object in your own code.
 */
template <class Base, typename T>
struct Delegate
{
    Attr<Base>&   m_attr;

    Delegate( Attr<Base>& attr ):
        m_attr(attr)
    {}

    operator T()
    {
        T value;
        Access<Base,T> access;
        m_attr.get(access,value);
        return value;
    }

    int operator=( T value )
    {
        return m_attr.set(value);
    }
};


/// Provides a unique type that acts like a native type
/**
 *  @note   This is used to inform the compiler of which template to
 *          instantiate. For instance GuardSize is typedefed as
 *          TypeWrap<std::size_t,0> while StackSize is typedefed as
 *          TypeWrap<std::size_t,1>. They both act just like std::size_t but
 *          they are in fact distinct types that the compiler can distinguish.
 */
template <typename T, unsigned int ID>
struct TypeWrap
{
    T m_data;

    /// does nothing
    TypeWrap()
    {}

    /// initialize the stored data to @p data
    TypeWrap( const T& data ):
        m_data(data)
    {}

    /// assigns the value to @p data
    TypeWrap<T,ID>& operator=( const T& data )
    {
        m_data = data;
        return *this;
    }

    /// implicit conversion to a reference of type @p T, means that this
    /// object can act exactly like a @p T object
    operator T&()
    {
        return m_data;
    }

    /// implicit conversion to a const reference of type @p T, means that this
    /// object can act exactly like a @p T object
    operator const T&() const
    {
        return m_data;
    }

};





}




#endif // ATTR_H_

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
 *  @brief  
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

        /// safe assignment of an attribute by value, use only for enumerations
        /// where the type is implied by the value
        template <typename T>
        int set( const T& value)
        {
            Assignment<Base,T> assignment(value);
            return assignment.set(*this);
        }

        /// safe assignment by an assignment object, use for generic values,
        /// i.e. GuardSize which is a size_t
        template <typename T>
        int set( const Assignment<Base,T>& assignment)
        {
            return assignment.set(*this);
        }

        /// safe value retrieval
        template <typename T>
        int get( const Access<Base,T>& access, T& value )
        {
            return access.get( *this, value );
        }

        /// stream assignment, unsafe, ignores error values returned
        template <typename T>
        Attr<Base>& operator << ( const T& value )
        {
            Assignment<Base,T> assignment(value);
            assignment.set(*this);
            return *this;
        }

        /// map operator, unsafe assignment and retrieval, ignores error values
        /// returned
        template <typename T>
        Delegate<Base,T> operator[]( const Access<Base,T>& access )
        {
            return Delegate<Base,T>(*this);
        }
};


/// two-way delegate, may assign or retrieve (unsafely) an attribute value
/// of an attribute object
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


template <typename T, unsigned int ID>
struct TypeWrap
{
    T m_data;

    TypeWrap( const T& data ):
        m_data(data)
    {

    }

    TypeWrap<T,ID>& operator=( const T& data )
    {
        m_data = data;
        return *this;
    }

    operator T&()
    {
        return m_data;
    }

    operator const T&() const
    {
        return m_data;
    }

};





}




#endif // ATTR_H_

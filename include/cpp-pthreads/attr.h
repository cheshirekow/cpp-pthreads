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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/attr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_ATTR_H_
#define CPP_PTHREADS_ATTR_H_

#include <cpp-pthreads/sizes.h>

namespace pthreads
{

/// Attributes object for type @p Base
/**
 *  For example, Attr<Thread> is the cpp-pthreads object wrapping
 *  pthread_attr_t
 */
template <class Base >              class  Attr;
template <class Base, typename T>   struct Assignment;
template <class Base, typename T>   struct Access;
template <class Base, typename T>   struct Delegate;

template <class Base>               struct AttrSize;


template <class Base, typename T>
struct Assignment
{
    T  m_value;
    Assignment( T value ):
        m_value(value)
    {}

    int set( Attr<Base>& attr ) const;
};

template <class Base, typename T>
struct Access
{
    Access(){}
    int get( Attr<Base>& attr, T& value ) const;
};


template <class Base>
class Attr
{
    private:
        char m_data [ AttrSize<Base>::size ];

    public:
        template <class Base2, typename T> friend class Assignment;
        template <class Base2, typename T> friend class Access;
        template <class Base2, typename T> friend class Delegate;

        /// initialize the object
        int init();

        /// destroy the object
        int destroy();

        /// safe assignment
        template <typename T>
        int set( const Assignment<Base,T>& assignment )
        {
            return assignment.set(*this);
        }

        /// assign an attribute
        template <typename T>
        int operator=( const Assignment<Base,T>& assignment )
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
        Attr<Base>& operator << ( const Assignment<Base,T>& assignment )
        {
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
        Assignment<Base,T> assignment(value);
        return m_attr.set(assignment);
    }
};







}




#endif // ATTR_H_

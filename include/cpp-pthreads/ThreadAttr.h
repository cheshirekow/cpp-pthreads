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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/ThreadAttr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_THREADATTR_H_
#define CPP_PTHREADS_THREADATTR_H_

#include <cpp-pthreads/Thread.h>
#include <cpp-pthreads/sizes.h>
#include <cpp-pthreads/enums.h>

namespace pthreads {

template <typename T>   struct Assignment;
template <typename T>   struct Access;
template <typename T>   struct Delegate;

template <>
struct Assignment<DetachState>
{
    DetachState  m_value;
    Assignment( DetachState value ):
        m_value(value)
    {}
    int set( Thread::Attr& attr ) const;
};

template <>
struct Access<DetachState>
{
    Access(){}
    int get( Thread::Attr& attr, DetachState& value ) const;
};

extern const Assignment<DetachState> SET_DETACHED;
extern const Assignment<DetachState> SET_JOINABLE;
extern const Access<DetachState>     DETACH_STATE;



template <>
struct Assignment<InheritSched>
{
    InheritSched  m_value;
    Assignment( InheritSched value ):
        m_value(value)
    {}
    int set( Thread::Attr& attr ) const;
};

template <>
struct Access<InheritSched>
{
    Access(){}
    int get( Thread::Attr& attr, InheritSched& value )const;
};


extern const Assignment<InheritSched> SET_INHERIT;
extern const Assignment<InheritSched> SET_EXPLICIT;
extern const Access<InheritSched>     INHERIT_SCHED;











class Thread::Attr
{
    private:
        char m_data [ sizeOf::attr ];

    public:
        template <typename T> friend class Assignment;
        template <typename T> friend class Access;
        template <typename T> friend class Delegate;

        /// pthread_attr_init
        int init();

        /// pthread_attr_destroy
        int destroy();

        /// safe assignment
        template <typename T>
        int set( const Assignment<T>& assignment )
        {
            return assignment.set(*this);
        }

        /// assign an attribute
        template <typename T>
        int operator=( const Assignment<T>& assignment )
        {
            return assignment.set(*this);
        }

        /// safe value retrieval
        template <typename T>
        int get( const Access<T>& access, T& value )
        {
            return access.get( *this, value );
        }

        /// stream assignment, unsafe, ignores error values returned
        template <typename T>
        Thread::Attr& operator << ( const Assignment<T>& assignment )
        {
            assignment.set(*this);
            return *this;
        }

        /// map operator, unsafe assignment and retrieval, ignores error values
        /// returned
        template <typename T>
        Delegate<T> operator[]( const Access<T>& access )
        {
            return Delegate<T>(*this);
        }
};



template<>
struct Delegate<DetachState>
{
    Thread::Attr&   m_attr;

    Delegate( Thread::Attr& attr ):
        m_attr(attr)
    {}

    operator DetachState()
    {
        DetachState value;
        m_attr.get(DETACH_STATE,value);
        return value;
    }

    int operator=( DetachState value )
    {
        Assignment<DetachState> assignment(value);
        return m_attr.set(assignment);
    }
};

template<>
struct Delegate<InheritSched>
{
    Thread::Attr&   m_attr;

    Delegate( Thread::Attr& attr ):
        m_attr(attr)
    {}

    operator InheritSched()
    {
        InheritSched value;
        m_attr.get(INHERIT_SCHED,value);
        return value;
    }

    int operator=( InheritSched value )
    {
        Assignment<InheritSched> assignment(value);
        return m_attr.set(assignment);
    }
};







}















#endif // THREADATTR_H_

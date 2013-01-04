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

/// private classes used by Thread::Attr
namespace     attr {

template <typename T>
struct Assignment
{
    virtual ~Assignment(){}
    virtual int set( Thread::Attr& attr ) const=0;
};

template <typename T>
struct Access
{
    virtual ~Access(){}
    virtual int get( Thread::Attr& attr, T& value ) const=0;
};

} // namespace attr


struct DetachStateDelegate:
    public attr::Assignment<DetachState>,
    public attr::Access<DetachState>
{
    DetachState  m_value;

    virtual ~DetachStateDelegate(){}

    /// assignment operator returns a copy for thread safety
    DetachStateDelegate operator=( DetachState value )
    {
        DetachStateDelegate other;
        other.m_value = value;
        return other;
    }

    virtual int set( Thread::Attr& attr ) const;
    virtual int get( Thread::Attr& attr, DetachState& value )const;
};


extern DetachStateDelegate DETACH_STATE;


class Thread::Attr
{
    private:
        char m_data [ sizeOf::attr ];

    public:
        friend class DetachStateDelegate;

        /// pthread_attr_init
        int init();

        /// pthread_attr_destroy
        int destroy();

        /// safe assignment
        template <typename T>
        int set( const attr::Assignment<T>& assignment )
        {
            return assignment.set(*this);
        }

        /// assign an attribute
        template <typename T>
        int operator=( const attr::Assignment<T>& assignment )
        {
            return assignment.set(*this);
        }

        /// retrieve an attribute, unsafe, error is ignored
        template <typename T>
        T operator[]( const attr::Access<T>& access )
        {
            T value;
            access.get( *this, value );
            return value;
        }

        /// safe value retrieval
        template <typename T>
        int get( const attr::Access<T>& access, T& value )
        {
            return access.get( *this, value );
        }

};

}















#endif // THREADATTR_H_

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

#include <cpp-pthreads/sizes.h>
#include <cpp-pthreads/enums.h>
#include <cpp-pthreads/attr.h>
#include <cpp-pthreads/Thread.h>
#include <cstdarg>


namespace pthreads {


struct GuardSize
{
    std::size_t m_data;

    GuardSize( const std::size_t& data ):
        m_data(data)
    {}

    GuardSize& operator=( std::size_t data )
    {
        m_data = data;
        return *this;
    }

    operator std::size_t&()
    {
        return m_data;
    }

    operator const std::size_t&() const
    {
        return m_data;
    }
};


extern const Access<Thread,DetachState>     DETACH_STATE;
extern const Access<Thread,InheritSched>    INHERIT_SCHED;
extern const Access<Thread,SchedPolicy>     SCHED_POLICY;
extern const Access<Thread,Scope>           SCOPE;
extern const Access<Thread,GuardSize>       GUARD_SIZE;

template<>
struct AttrSize<Thread>
{
    static const unsigned int size = sizeOf::attr;
};






}















#endif // THREADATTR_H_

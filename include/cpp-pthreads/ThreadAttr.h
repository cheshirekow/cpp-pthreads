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
 *  @file   include/cpp-pthreads/ThreadAttr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_THREADATTR_H_
#define CPP_PTHREADS_THREADATTR_H_

#include <cpp-pthreads/enums.h>
#include <cpp-pthreads/Attr.h>
#include <cpp-pthreads/Thread.h>
#include <cstdarg>
#include <pthread.h>

namespace pthreads {


/// A unique type which acts just like size_t but is distinct in the
/// eyes of the compiler
typedef TypeWrap<std::size_t,0>   GuardSize;

/// A unique type which acts just like size_t but is distinct in the
/// eyes of the compiler
typedef TypeWrap<std::size_t,1>   StackSize;

/// Simply encapsulates the stack address and size in a single object
struct Stack
{
    void*       addr;
    std::size_t size;

    Stack( void* addr=0, std::size_t size=0):
        addr(addr),
        size(size)
    {}
};

/// provides access to the detachstate field of a pthread_attr_t
extern const Access<Thread,DetachState>     DETACH_STATE;

/// provides access to the inheritsched field of a pthread_attr_t
extern const Access<Thread,InheritSched>    INHERIT_SCHED;

/// provides access to the schedpolicy field of a pthread_attr_t
extern const Access<Thread,SchedPolicy>     SCHED_POLICY;

/// provides access to the scope field of a pthread_attr_t
extern const Access<Thread,Scope>           SCOPE;

/// provides access to the guardsize field of a pthread_attr_t
extern const Access<Thread,GuardSize>       GUARD_SIZE;

/// provides access to the stack field of a pthread_attr_t, including
/// stack address and size
extern const Access<Thread,Stack>           STACK;

/// provides access to the stacksize field of a pthread_attr_t
extern const Access<Thread,StackSize>       STACK_SIZE;

/// A simple way of telling Attr<Thread> that it's storage type
/// is pthread_attr_t
template<>
struct AttrType<Thread>
{
    typedef pthread_attr_t type;
};






}















#endif // THREADATTR_H_

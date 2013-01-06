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



typedef TypeWrap<std::size_t,0>   GuardSize;
typedef TypeWrap<std::size_t,1>   StackSize;

struct Stack
{
    void*       addr;
    std::size_t size;

    Stack( void* addr=0, std::size_t size=0):
        addr(addr),
        size(size)
    {}
};

extern const Access<Thread,DetachState>     DETACH_STATE;
extern const Access<Thread,InheritSched>    INHERIT_SCHED;
extern const Access<Thread,SchedPolicy>     SCHED_POLICY;
extern const Access<Thread,Scope>           SCOPE;
extern const Access<Thread,GuardSize>       GUARD_SIZE;
extern const Access<Thread,Stack>           STACK_ADDR;
extern const Access<Thread,StackSize>       STACK_SIZE;

template<>
struct AttrType<Thread>
{
    typedef pthread_attr_t type;
};






}















#endif // THREADATTR_H_

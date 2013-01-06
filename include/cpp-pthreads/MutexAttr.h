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
 *  @file   include/cpp-pthreads/MutexAttr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_MUTEXATTR_H_
#define CPP_PTHREADS_MUTEXATTR_H_



#include <cpp-pthreads/enums.h>
#include <cpp-pthreads/Attr.h>
#include <cpp-pthreads/Mutex.h>
#include <cstdarg>
#include <ctime>
#include <pthread.h>


namespace pthreads {

typedef TypeWrap<int,0> PriorityCeiling;

extern const Access<Mutex,PriorityCeiling>  PRIORITY_CEILING;
extern const Access<Mutex,Protocol>         PROTOCOL;
extern const Access<Mutex,PShared>          M_PSHARED;
extern const Access<Mutex,Type>             TYPE;


template<>
struct AttrType<Mutex>
{
    typedef pthread_mutexattr_t type;
};





}














#endif // MUTEXATTR_H_

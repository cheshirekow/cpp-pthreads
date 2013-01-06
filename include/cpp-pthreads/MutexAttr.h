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
 *  @brief  Specializations for Attr<Mutex>
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

/// A unique type which acts just like an int but is distinct in the
/// eyes of the compiler
typedef TypeWrap<int,0> PriorityCeiling;

/// provides access to the prioceil field of a pthread_mutexattr_t
extern const Access<Mutex,PriorityCeiling>  PRIORITY_CEILING;

/// provides access to the protocol field of a pthread_mutexattr_t
extern const Access<Mutex,Protocol>         PROTOCOL;

/// provides access to the pshared field of a pthread_mutexattr_t
extern const Access<Mutex,PShared>          M_PSHARED;

/// provides access to the type field of a pthread_mutexattr_t
extern const Access<Mutex,Type>             TYPE;

/// A simple way of telling Attr<Mutex> that it's storage type
/// is pthread_mutexattr_t
template<>
struct AttrType<Mutex>
{
    typedef pthread_mutexattr_t type;
};





}














#endif // MUTEXATTR_H_

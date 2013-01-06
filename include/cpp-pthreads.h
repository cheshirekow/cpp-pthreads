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
 *  @file   include/cpp-pthreads.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_H_
#define CPP_PTHREADS_H_

#include <pthread.h>
#include <cpp-pthreads/enums.h>
#include <cpp-pthreads/Attr.h>
#include <cpp-pthreads/Condition.h>
#include <cpp-pthreads/ConditionAttr.h>
#include <cpp-pthreads/Key.h>
#include <cpp-pthreads/Mutex.h>
#include <cpp-pthreads/MutexAttr.h>
#include <cpp-pthreads/Thread.h>
#include <cpp-pthreads/ThreadAttr.h>

/// Wraps posix-threads (pthreads.h) with object oriented API
namespace pthreads{}














#endif // CPP_PTHREADS_H_

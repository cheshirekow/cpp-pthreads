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
 *  @brief  Main include, simply includes other header files
 */

#ifndef CPP_PTHREADS_H_
#define CPP_PTHREADS_H_

#include <pthread.h>
#include <cpp_pthreads/enums.h>
#include <cpp_pthreads/attr.h>
#include <cpp_pthreads/condition.h>
#include <cpp_pthreads/condition_attr.h>
#include <cpp_pthreads/key.h>
#include <cpp_pthreads/mutex.h>
#include <cpp_pthreads/mutex_attr.h>
#include <cpp_pthreads/thread.h>
#include <cpp_pthreads/thread_attr.h>

/// Wraps posix-threads (pthreads.h) with object oriented API
namespace pthreads{}














#endif // CPP_PTHREADS_H_

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
 *  @file   include/cpp-pthreads/ConditionAttr.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  Specializations for Attr<Condition>
 */

#ifndef CPP_PTHREADS_CONDITIONATTR_H_
#define CPP_PTHREADS_CONDITIONATTR_H_

#include <pthread.h>

#include <cstdarg>
#include <ctime>

#include <cpp_pthreads/attr.h>
#include <cpp_pthreads/condition.h>
#include <cpp_pthreads/enums.h>

namespace pthreads {

/// A unique type which acts just like clockid_t but is distinct in the
/// eyes of the compiler
typedef TypeWrap<clockid_t, 0> Clock;

/// provides access to the clock field of a pthread_condrattr_t
extern const Access<Condition, Clock> CLOCK;

/// provides access to the pshared field of a pthread_condrattr_t
extern const Access<Condition, PShared> C_PSHARED;

/// A simple way of telling Attr<Condition> that it's storage type
/// is pthread_condattr_t
template<>
struct AttrType<Condition> {
  typedef pthread_condattr_t type;
};

}

#endif // CONDATTR_H_

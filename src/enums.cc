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
 *  @file   src/enums.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include "cpp_pthreads/enums.h"

#include <pthread.h>
#include <sched.h>


#define DEFINEMAP( name ) \
    template <> int* getEnumMap<name>(){ return name##Map; }

namespace pthreads {

int DetachStateMap[] = {
  PTHREAD_CREATE_DETACHED,
  PTHREAD_CREATE_JOINABLE
};

int InheritSchedMap[] = {
  PTHREAD_INHERIT_SCHED,
  PTHREAD_EXPLICIT_SCHED
};

int SchedPolicyMap[] = {
  SCHED_OTHER,
  SCHED_FIFO,
  SCHED_RR,
#ifdef SCHED_BATCH
  SCHED_BATCH,
#else
  -1,
#endif
#ifdef SCHED_IDLE
  SCHED_IDLE,
#else
  -1,
#endif
#ifdef SCHED_SPORADIC
  SCHED_SPORADIC,
#else
  -1,
#endif
};

int ScopeMap[] = {
  PTHREAD_SCOPE_SYSTEM,
  PTHREAD_SCOPE_PROCESS
};

int PSharedMap[] = {
  PTHREAD_PROCESS_SHARED,
  PTHREAD_PROCESS_PRIVATE
};

int ProtocolMap[] = {
  PTHREAD_PRIO_NONE,
  PTHREAD_PRIO_INHERIT,
  PTHREAD_PRIO_PROTECT
};

int TypeMap[] = {
  PTHREAD_MUTEX_NORMAL,
  PTHREAD_MUTEX_ERRORCHECK,
  PTHREAD_MUTEX_RECURSIVE,
  PTHREAD_MUTEX_DEFAULT
};

DEFINEMAP(DetachState);
DEFINEMAP(InheritSched);
DEFINEMAP(SchedPolicy);
DEFINEMAP(Scope);
DEFINEMAP(PShared);
DEFINEMAP(Protocol);
DEFINEMAP(Type)

template<> DetachState getEnum<DetachState>(int val) {
  switch (val) {
    case PTHREAD_CREATE_DETACHED:
      return DETACHED;

    case PTHREAD_CREATE_JOINABLE:
      return JOINABLE;

    default:
      return INVALID_DETACH_STATE;
  }
}

template<> InheritSched getEnum<InheritSched>(int val) {
  switch (val) {
    case PTHREAD_INHERIT_SCHED:
      return INHERIT;

    case PTHREAD_EXPLICIT_SCHED:
      return EXPLICIT;

    default:
      return INVALID_INHERIT_SCHED;
  }
}

template<> SchedPolicy getEnum<SchedPolicy>(int val) {
  switch (val) {
    case SCHED_OTHER:
      return OTHER;

    case SCHED_FIFO:
      return FIFO;

    case SCHED_RR:
      return RR;

#ifdef SCHED_BATCH
    case SCHED_BATCH:
      return BATCH;
#endif
#ifdef SCHED_IDLE
    case SCHED_IDLE:
      return IDLE;
#endif
#ifdef SCHED_SPORADIC
      case SCHED_SPORADIC:
      return SPORADIC;
#endif

    default:
      return INVALID_SCHED_POLICY;
  }
}

template<> Scope getEnum<Scope>(int val) {
  switch (val) {
    case PTHREAD_SCOPE_SYSTEM:
      return SYSTEM;

    case PTHREAD_SCOPE_PROCESS:
      return PROCESS;

    default:
      return INVALID_SCOPE;
  }
}

template<> PShared getEnum<PShared>(int val) {
  switch (val) {
    case PTHREAD_PROCESS_SHARED:
      return SHARED;

    case PTHREAD_PROCESS_PRIVATE:
      return PRIVATE;

    default:
      return INVALID_PSHARED;
  }
}

template<> Protocol getEnum<Protocol>(int val) {
  switch (val) {
    case PTHREAD_PRIO_NONE:
      return PRIO_NONE;

    case PTHREAD_PRIO_INHERIT:
      return PRIO_INHERIT;

    case PTHREAD_PRIO_PROTECT:
      return PRIO_PROTECT;

    default:
      return INVALID_PROTOCOL;
  }
}

template<> Type getEnum<Type>(int val) {
  switch (val) {
    case PTHREAD_MUTEX_NORMAL:
      return NORMAL;

    case PTHREAD_MUTEX_ERRORCHECK:
      return ERROR_CHECK;

    case PTHREAD_MUTEX_RECURSIVE:
      return RECURSIVE;

#if PTHREAD_MUTEX_NORMAL != PTHREAD_MUTEX_DEFAULT
    case PTHREAD_MUTEX_DEFAULT:
      return DEFAULT;
#endif

    default:
      return INVALID_TYPE;
  }
}

}   // namespace pthreads


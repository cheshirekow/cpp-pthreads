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
 *  @file   include/cpp-pthreads/Mutex.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  Definition of Mutex class
 */

#ifndef CPP_PTHREADS_MUTEX_H_
#define CPP_PTHREADS_MUTEX_H_

#include <pthread.h>

#include <cpp_pthreads/attr.h>

namespace pthreads {

class Mutex;

/// Points to a locked mutex and unlocks the mutex when destroyed
/**
 *  Usage:
 *  @code
 Mutex mutex;

 {
 // constructor locks the mutex here
 ScopedLock lock(mutex);

 // ... (do something)
 } // when lock goes out of scope the destructor releases the lock on the
 // mutex
 @endcode
 */
class ScopedLock {
 private:
  ///< the mutex being locked
  Mutex* m_mutex;

 public:
  /// default constructor has an empty mutex
  ScopedLock(Mutex* mutex = 0);

  /// explicit creation, locks the mutex
  ScopedLock(Mutex& mutex);

  /// move constructor transfers ownership of the lock to the new object
  //ScopedLock( ScopedLock&& other );

  /// unlock the mutex
  ~ScopedLock();

  /// assignment transfers ownership of the lock to the assignee
  /**
   *  If the assignee already owns a mutex, that one is unlocked
   */
  ScopedLock& operator=(ScopedLock& other);

  /// swaps mutexes with another lock
  void swap(ScopedLock& other);
};

/// forward declaration
class Condition;

/// a mutual exclusion lock
class Mutex {
 private:
  pthread_mutex_t m_data;

 public:
  friend class Condition;

  /// calls pthread_mutex_init
  int init();

  /// calls pthread_mutex_init with an attribute object
  int init(const Attr<Mutex>& attr);

  /// calls pthread_mutex_destroy
  int destroy();

  /// change the priority ceiling
  int setPriorityCeiling(int newCeil, int* oldCeil);

  /// get the priority ceiling
  int getPriorityCeiling(int&);

  /// lock the mutex, block until succeed
  int lock();

  /// try to lock the mutex, but dont block
  int trylock();

  /// return a scoped lock
  ScopedLock scopedLock();

  /// unlock the mutex after a successful lock
  int unlock();
};

}

#endif // MUTEX_H_

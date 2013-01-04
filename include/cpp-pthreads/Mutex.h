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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/Mutex.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_MUTEX_H_
#define CPP_PTHREADS_MUTEX_H_

#include <cpp-pthreads/Attr.h>
#include <pthread.h>

namespace pthreads {

class Mutex;

/// provides a pointer to a locked mutex and unlocks the mutex when destroyed
class ScopedLock
{
    private:
        Mutex&  m_mutex;

    public:
        explicit ScopedLock( Mutex& mutex );

        ~ScopedLock();
};

/// forward declaration
class Condition;

/// a mutual exclusion lock
class Mutex
{
    private:
        pthread_mutex_t m_data;

    public:
        friend class Condition;

        /// calls pthread_mutex_init
        int init();

        /// calls pthread_mutex_init with an attribute object
        int init( const Attr<Mutex>& attr );

        /// calls pthread_mutex_destroy
        int destroy();

        /// change the priority ceiling
        int setPriorityCeiling( int newCeil, int* oldCeil );

        /// get the priority ceiling
        int getPriorityCeiling( int& );

        /// lock the mutex, block until succeed
        int lock();

        /// try to lock the mutex, but dont block
        int trylock();

        /// unlock the mutex after a successful lock
        int unlock();
};

}















#endif // MUTEX_H_

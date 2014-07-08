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
 *  @file   include/cpp-pthreads/Condition.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  Definition of Condition class
 */

#ifndef CPP_PTHREADS_CONDITION_H_
#define CPP_PTHREADS_CONDITION_H_

#include <pthread.h>

#include <cpp_pthreads/Attr.h>
#include <cpp_pthreads/Mutex.h>

namespace pthreads {


/// Allows multiple threads to wait until a condition is satisfied
/**
 *  @note   A condition variable is always used with a mutex. When a condition
 *          is signaled, one thread that is currently waiting on that
 *          condition is woken up, and aquires the mutex that associated
 *          with the wait.
 */
class Condition
{
    private:
        pthread_cond_t m_data;

    public:
        /// calls initializes a condition variable with default attributes
        int init();

        /// initializes a condition variable with the specified attributes
        int init( const Attr<Condition>& attr );

        /// destroys a condition variable
        int destroy();

        /// signals all threads waiting on the condition
        int broadcast();

        /// signals one thread waiting on the condition
        int signal();

        /// called by a thread that wishes to wait on this condition
        int wait( Mutex& mutex );

};

}















#endif // CONDITION_H_

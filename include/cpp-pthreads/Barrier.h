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
 *  @file   include/cpp-pthreads/Barrier.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_BARRIER_H_
#define CPP_PTHREADS_BARRIER_H_

#include <cpp-pthreads/Attr.h>
#include <pthread.h>

namespace pthreads {

/// A barrier is an object which synchronizes a fixed number of threads at
/// a specific point.
/**
 *  @note   once initialized, threads that wish to synchronize call
 *          wait() on a barrier. Once @p count threads are waiting on
 *          the barrier, they will all be released.
 */
class Barrier
{
    private:
        pthread_barrier_t m_data;

    public:
        /// initialize a barrier for @p count threads using default attributes
        int init( unsigned count );

        /// initialize a barrier for @p count threads using the specified
        /// attributes
        int init( const Attr<Barrier>& attr, unsigned count );

        /// destroy the barrier
        int destroy();

        /// called by a thread which wishes to synchronize on the barrier.
        /// Will block until @p count threads are all wait()ing on the barrier
        int wait(  );

};

}



#endif // BARRIER_H_

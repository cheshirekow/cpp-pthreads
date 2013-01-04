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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/src/Barrier.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp-pthreads/Barrier.h>
#include <cpp-pthreads/BarrierAttr.h>
#include <pthread.h>

namespace pthreads {

int Barrier::init( unsigned count )
{
    pthread_barrier_t* barrier =
            reinterpret_cast< pthread_barrier_t* >(m_data);
    return pthread_barrier_init( barrier, 0, count );
}

int Barrier::init( const Attr<Barrier>& attr_in, unsigned count )
{
    pthread_barrier_t* barrier =
            reinterpret_cast< pthread_barrier_t* >(m_data);
    const pthread_barrierattr_t* attr =
            reinterpret_cast< const pthread_barrierattr_t*>(attr_in.m_data);
    return pthread_barrier_init( barrier, 0, count );
}

int Barrier::destroy()
{
    pthread_barrier_t* barrier =
            reinterpret_cast< pthread_barrier_t* >(m_data);
    return pthread_barrier_destroy( barrier );
}

int Barrier::wait()
{
    pthread_barrier_t* barrier =
            reinterpret_cast< pthread_barrier_t* >(m_data);
    return pthread_barrier_wait( barrier );
}


}





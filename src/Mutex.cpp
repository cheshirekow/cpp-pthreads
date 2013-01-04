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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/src/Mutex.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp-pthreads/Mutex.h>
#include <pthread.h>

namespace pthreads {

ScopedLock::ScopedLock( Mutex& mutex ):
    m_mutex(mutex)
{
    m_mutex.lock();
}

ScopedLock::~ScopedLock(  )
{
    m_mutex.unlock();
}

Mutex::Mutex(){}

int Mutex::init()
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_init(data,0);
}

int Mutex::destroy()
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_destroy(data);
}

int Mutex::setPriorityCeiling( int newCeil, int* oldCeil )
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_setprioceiling(data,newCeil,oldCeil);
}

int Mutex::getPriorityCeiling( int& ceil )
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_getprioceiling(data,&ceil);
}

int Mutex::lock()
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_lock(data);
}

int Mutex::trylock()
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_trylock(data);
}

int Mutex::unlock()
{
    pthread_mutex_t* data = reinterpret_cast<pthread_mutex_t*>(m_data);
    return pthread_mutex_unlock(data);
}

}










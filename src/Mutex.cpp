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
 *  @file   src/Mutex.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp-pthreads/Mutex.h>
#include <cpp-pthreads/MutexAttr.h>
#include <pthread.h>

namespace pthreads {

ScopedLock::ScopedLock( Mutex* mutex ):
    m_mutex(mutex)
{
    if(m_mutex)
        mutex->lock();
}

ScopedLock::ScopedLock( Mutex& mutex ):
    m_mutex(&mutex)
{
    m_mutex->lock();
}

//ScopedLock::ScopedLock( ScopedLock&& other )
//{
//    m_mutex       = other.m_mutex;
//    other.m_mutex = 0;
//}


ScopedLock::~ScopedLock(  )
{
    if(m_mutex)
        m_mutex->unlock();
}

ScopedLock& ScopedLock::operator=( ScopedLock& other )
{
    if(m_mutex)
        m_mutex->unlock();
    m_mutex       = other.m_mutex;
    other.m_mutex = 0;

    return *this;
}

void ScopedLock::swap( ScopedLock& other )
{
    Mutex* tmp    = m_mutex;
    m_mutex       = other.m_mutex;
    other.m_mutex = tmp;
}

int Mutex::init()
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_init(mutex,0);
}

int Mutex::init( const Attr<Mutex>& attr_in )
{
    pthread_mutex_t* mutex = &m_data;
    const pthread_mutexattr_t* attr = &(attr_in.m_data);
    return pthread_mutex_init(mutex,attr);
}

int Mutex::destroy()
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_destroy(mutex);
}

int Mutex::setPriorityCeiling( int newCeil, int* oldCeil )
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_setprioceiling(mutex,newCeil,oldCeil);
}

int Mutex::getPriorityCeiling( int& ceil )
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_getprioceiling(mutex,&ceil);
}

int Mutex::lock()
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_lock(mutex);
}

int Mutex::trylock()
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_trylock(mutex);
}

ScopedLock Mutex::scopedLock()
{
    return this;
}

int Mutex::unlock()
{
    pthread_mutex_t* mutex = &m_data;
    return pthread_mutex_unlock(mutex);
}

}










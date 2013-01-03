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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/src/cpp-pthreads/Thread.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */


#include <cpp-pthreads/Thread.h>
#include <pthread.h>

namespace pthreads
{

Thread::Thread( id_t id ):
    m_pthread(id)
{}

Thread::Thread( routine_t start, void* arg )
{
    pthread_attr_t x;
    pthread_t thread_id;
    pthread_create(&thread_id,0,start,arg);
    m_pthread = thread_id;
}

int Thread::join(void** value_ptr)
{
    pthread_t thread_id = m_pthread;
    return pthread_join(thread_id,value_ptr);
}

int Thread::detach()
{
    pthread_t thread_id = m_pthread;
    return pthread_detach(thread_id);
}

int Thread::cancel()
{
    pthread_t thread_id = m_pthread;
    return pthread_cancel( thread_id );
}

bool Thread::operator==( const Thread& other )
{
    pthread_t thread_a = m_pthread;
    pthread_t thread_b = other.m_pthread;
    return pthread_equal(thread_a,thread_b);
}

void Thread::exit( void* value_ptr )
{
    pthread_exit( value_ptr );
}

Thread Thread::self()
{
    pthread_t thread_id = pthread_self();
    return Thread(thread_id);
}


}








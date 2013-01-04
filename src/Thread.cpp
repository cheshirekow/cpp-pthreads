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
#include <signal.h>

namespace pthreads
{


int Thread::launch( routine_t start, void* arg )
{
    pthread_t* thread = reinterpret_cast<pthread_t*>(m_data);
    return pthread_create(thread,0,start,arg);
}

int Thread::join(void** value_ptr)
{
    pthread_t* thread = reinterpret_cast<pthread_t*>(m_data);
    return pthread_join(*thread,value_ptr);
}

int Thread::detach()
{
    pthread_t* thread = reinterpret_cast<pthread_t*>(m_data);
    return pthread_detach(*thread);
}

int Thread::cancel()
{
    pthread_t* thread = reinterpret_cast<pthread_t*>(m_data);
    return pthread_cancel( *thread );
}

int Thread::kill( int sig )
{
    pthread_t* thread = reinterpret_cast<pthread_t*>(m_data);
    return pthread_kill(*thread,sig);
}

bool Thread::operator==( const Thread& other )
{
          pthread_t* thread_a =
                        reinterpret_cast<pthread_t*>(m_data);
    const pthread_t* thread_b =
                        reinterpret_cast<const pthread_t*>(other.m_data);

    return pthread_equal(*thread_a,*thread_b);
}

void Thread::exit( void* value_ptr )
{
    pthread_exit( value_ptr );
}

Thread Thread::self()
{
    Thread thread;
    pthread_t* thread_id = reinterpret_cast<pthread_t*>(thread.m_data);
    *thread_id = pthread_self();
    return thread;
}


}








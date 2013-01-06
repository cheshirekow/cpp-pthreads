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
 *  @file   src/Condition.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp-pthreads/Condition.h>
#include <cpp-pthreads/ConditionAttr.h>
#include <pthread.h>

namespace pthreads {

int Condition::init()
{
    pthread_cond_t* cond = &m_data;
    return pthread_cond_init(cond,0);
}

int Condition::init(const Attr<Condition>& attr_in)
{
    pthread_cond_t* cond = &m_data;
    const pthread_condattr_t* attr = &(attr_in.m_data);
    return pthread_cond_init(cond,attr);
}

int Condition::destroy()
{
    pthread_cond_t* cond = &m_data;
    return pthread_cond_destroy(cond);
}

int Condition::broadcast()
{
    pthread_cond_t* cond = &m_data;
    return pthread_cond_broadcast(cond);
}

int Condition::signal()
{
    pthread_cond_t* cond = &m_data;
    return pthread_cond_signal(cond);
}

int Condition::wait( Mutex& mutex_in )
{
    pthread_cond_t* cond = &m_data;
    pthread_mutex_t* mutex = &(mutex_in.m_data);
    return pthread_cond_wait(cond,mutex);
}


}








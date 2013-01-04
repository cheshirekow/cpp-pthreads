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


#include <cpp-pthreads/ThreadAttr.h>
#include <pthread.h>

namespace pthreads
{

const DetachStateAssignment SET_DETACHED(DETACHED);
const DetachStateAssignment SET_JOINABLE(JOINABLE);
const DetachStateAccess     DETACH_STATE;

int DetachStateAssignment::set( Thread::Attr& attr_in ) const
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(attr_in.m_data);
    return pthread_attr_setdetachstate( attr, mapEnum(m_value) );
}

int DetachStateAccess::get( Thread::Attr& attr_in, DetachState& value ) const
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getdetachstate( attr, &outVal );
    value = getEnum<DetachState>(outVal);
    return returnVal;
}


const InheritSchedAssignment SET_INHERIT(INHERIT);
const InheritSchedAssignment SET_EXPLICIT(EXPLICIT);
const InheritSchedAccess     INHERIT_SCHED;

int InheritSchedAssignment::set( Thread::Attr& attr_in ) const
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(attr_in.m_data);
    return pthread_attr_setinheritsched( attr, mapEnum(m_value) );
}

int InheritSchedAccess::get( Thread::Attr& attr_in, InheritSched& value ) const
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getinheritsched( attr, &outVal );
    value = getEnum<InheritSched>(outVal);
    return returnVal;
}



int Thread::Attr::init()
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(m_data);
    return pthread_attr_init( attr );
}

int Thread::Attr::destroy()
{
    pthread_attr_t* attr = reinterpret_cast< pthread_attr_t* >(m_data);
    return pthread_attr_destroy( attr );
}



}








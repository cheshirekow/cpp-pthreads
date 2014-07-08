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
 *  @file   src/ThreadAttr.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */


#include <cpp_pthreads/ThreadAttr.h>
#include <pthread.h>

namespace pthreads
{

const Access<Thread,DetachState>    DETACH_STATE;
const Access<Thread,InheritSched>   INHERIT_SCHED;
const Access<Thread,SchedPolicy>    SCHED_POLICY;
const Access<Thread,Scope>          SCOPE;
const Access<Thread,GuardSize>      GUARD_SIZE;





template <>
int Assignment<Thread,DetachState>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setdetachstate( attr, mapEnum(m_value) );
}

template <>
int Access<Thread,DetachState>::get( Attr<Thread>& attr_in, DetachState& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getdetachstate( attr, &outVal );
    value = getEnum<DetachState>(outVal);
    return returnVal;
}





template <>
int Assignment<Thread,InheritSched>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setinheritsched( attr, mapEnum(m_value) );
}




template <>
int Access<Thread,InheritSched>::get( Attr<Thread>& attr_in, InheritSched& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getinheritsched( attr, &outVal );
    value = getEnum<InheritSched>(outVal);
    return returnVal;
}



template <>
int Assignment<Thread,SchedPolicy>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setschedpolicy( attr, mapEnum(m_value) );
}

template <>
int Access<Thread,SchedPolicy>::get( Attr<Thread>& attr_in, SchedPolicy& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getschedpolicy( attr, &outVal );
    value = getEnum<SchedPolicy>(outVal);
    return returnVal;
}





template <>
int Assignment<Thread,Scope>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setscope( attr, mapEnum(m_value) );
}

template <>
int Access<Thread,Scope>::get( Attr<Thread>& attr_in, Scope& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_attr_getscope( attr, &outVal );
    value = getEnum<Scope>(outVal);
    return returnVal;
}




template <>
int Assignment<Thread,GuardSize>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setguardsize( attr, m_value );
}

template <>
int Access<Thread,GuardSize>::get( Attr<Thread>& attr_in, GuardSize& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    size_t outVal;
    int returnVal =  pthread_attr_getguardsize( attr, &outVal );
    value = outVal;
    return returnVal;
}




template <>
int Assignment<Thread,Stack>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setstack( attr, m_value.addr, m_value.size );
}

template <>
int Access<Thread,Stack>::get( Attr<Thread>& attr_in, Stack& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    void* outVal;
    size_t outVal2;
    int returnVal =  pthread_attr_getstack( attr, &outVal, &outVal2 );
    value.addr = outVal;
    value.size = outVal2;
    return returnVal;
}




template <>
int Assignment<Thread,StackSize>::set( Attr<Thread>& attr_in ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    return pthread_attr_setstacksize( attr, m_value );
}

template <>
int Access<Thread,StackSize>::get( Attr<Thread>& attr_in, StackSize& value ) const
{
    pthread_attr_t* attr = &(attr_in.m_data);
    size_t outVal;
    int returnVal =  pthread_attr_getstacksize( attr, &outVal );
    value = outVal;
    return returnVal;
}





template <>
int Attr<Thread>::init()
{
    pthread_attr_t* attr = &m_data;
    return pthread_attr_init( attr );
}

template <>
int Attr<Thread>::destroy()
{
    pthread_attr_t* attr = &m_data;
    return pthread_attr_destroy( attr );
}



}








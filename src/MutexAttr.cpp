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
 *  @file   src/MutexAttr.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */




#include <cpp-pthreads/MutexAttr.h>
#include <pthread.h>

namespace pthreads
{


const Access<Mutex,PriorityCeiling>  PRIORITY_CEILING;
const Access<Mutex,Protocol>         PROTOCOL;
const Access<Mutex,PShared>          M_PSHARED;
const Access<Mutex,Type>             TYPE;



template <>
int Assignment<Mutex,PShared>::set( Attr<Mutex>& attr_in ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    return pthread_mutexattr_setpshared( attr, mapEnum(m_value) );
}

template <>
int Access<Mutex,PShared>::get( Attr<Mutex>& attr_in, PShared& value ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_mutexattr_getpshared( attr, &outVal );
    value = getEnum<PShared>(outVal);
    return returnVal;
}




template <>
int Assignment<Mutex,PriorityCeiling>::set( Attr<Mutex>& attr_in ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    return pthread_mutexattr_setprioceiling( attr, m_value );
}

template <>
int Access<Mutex,PriorityCeiling>::get( Attr<Mutex>& attr_in, PriorityCeiling& value ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_mutexattr_getprioceiling( attr, &outVal );
    value = outVal;
    return returnVal;
}




template <>
int Assignment<Mutex,Protocol>::set( Attr<Mutex>& attr_in ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    return pthread_mutexattr_setprotocol( attr, mapEnum(m_value) );
}

template <>
int Access<Mutex,Protocol>::get( Attr<Mutex>& attr_in, Protocol& value ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_mutexattr_getprotocol( attr, &outVal );
    value = getEnum<Protocol>(outVal);
    return returnVal;
}




template <>
int Assignment<Mutex,Type>::set( Attr<Mutex>& attr_in ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    return pthread_mutexattr_settype( attr, mapEnum(m_value) );
}

template <>
int Access<Mutex,Type>::get( Attr<Mutex>& attr_in, Type& value ) const
{
    pthread_mutexattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_mutexattr_gettype( attr, &outVal );
    value = getEnum<Type>(outVal);
    return returnVal;
}




template <>
int Attr<Mutex>::init()
{
    pthread_mutexattr_t* attr = &m_data;
    return pthread_mutexattr_init( attr );
}

template <>
int Attr<Mutex>::destroy()
{
    pthread_mutexattr_t* attr = &m_data;
    return pthread_mutexattr_destroy( attr );
}



}

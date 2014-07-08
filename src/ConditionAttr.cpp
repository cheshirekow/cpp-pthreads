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
 *  @file   src/ConditionAttr.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */



#include <cpp_pthreads/ConditionAttr.h>
#include <pthread.h>

namespace pthreads
{


const Access<Condition,Clock>     CLOCK;
const Access<Condition,PShared>   C_PSHARED;




template <>
int Assignment<Condition,Clock>::set( Attr<Condition>& attr_in ) const
{
    pthread_condattr_t* attr = &(attr_in.m_data);
    return pthread_condattr_setclock( attr, m_value );
}

template <>
int Access<Condition,Clock>::get( Attr<Condition>& attr_in, Clock& value ) const
{
    pthread_condattr_t* attr = &(attr_in.m_data);
    clockid_t outVal;
    int returnVal =  pthread_condattr_getclock( attr, &outVal );
    value = outVal;
    return returnVal;
}




template <>
int Assignment<Condition,PShared>::set( Attr<Condition>& attr_in ) const
{
    pthread_condattr_t* attr = &(attr_in.m_data);
    return pthread_condattr_setpshared( attr, mapEnum(m_value) );
}

template <>
int Access<Condition,PShared>::get( Attr<Condition>& attr_in, PShared& value ) const
{
    pthread_condattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_condattr_getpshared( attr, &outVal );
    value = getEnum<PShared>(outVal);
    return returnVal;
}




template <>
int Attr<Condition>::init()
{
    pthread_condattr_t* attr = &(m_data);
    return pthread_condattr_init( attr );
}

template <>
int Attr<Condition>::destroy()
{
    pthread_condattr_t* attr = &(m_data);
    return pthread_condattr_destroy( attr );
}



}









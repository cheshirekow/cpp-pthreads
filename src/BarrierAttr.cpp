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
 *  @file   src/BarrierAttr.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp-pthreads/BarrierAttr.h>
#include <pthread.h>

namespace pthreads {


const Access<Barrier,PShared>          B_PSHARED;



template <>
int Assignment<Barrier,PShared>::set( Attr<Barrier>& attr_in ) const
{
    pthread_barrierattr_t* attr = &(attr_in.m_data);
    return pthread_barrierattr_setpshared( attr, mapEnum(m_value) );
}

template <>
int Access<Barrier,PShared>::get( Attr<Barrier>& attr_in, PShared& value ) const
{
    pthread_barrierattr_t* attr = &(attr_in.m_data);
    int outVal;
    int returnVal =  pthread_barrierattr_getpshared( attr, &outVal );
    value = getEnum<PShared>(outVal);
    return returnVal;
}




template <>
int Attr<Barrier>::init()
{
    pthread_barrierattr_t* attr = &m_data;
    return pthread_barrierattr_init( attr );
}

template <>
int Attr<Barrier>::destroy()
{
    pthread_barrierattr_t* attr = &m_data;
    return pthread_barrierattr_destroy( attr );
}

}

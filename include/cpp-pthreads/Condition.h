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
 *  @file   include/cpp-pthreads/Condition.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_CONDITION_H_
#define CPP_PTHREADS_CONDITION_H_

#include <cpp-pthreads/Attr.h>
#include <cpp-pthreads/Mutex.h>
#include <pthread.h>

namespace pthreads {

class Condition
{
    private:
        pthread_cond_t m_data;

    public:
        /// calls pthread_cond_init
        int init();

        /// calls pthread_cond_init
        int init( const Attr<Condition>& attr );

        /// calls pthread_cond_destroy
        int destroy();

        /// calls pthread_cond_broadcast
        int broadcast();

        /// calls pthread_cond_signal
        int signal();

        /// calls pthread_cond_wait
        int wait( Mutex& mutex );

};

}















#endif // CONDITION_H_

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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/Key.h
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_KEY_H_
#define CPP_PTHREADS_KEY_H_


#include <pthread.h>

namespace pthreads {

class Key
{
    public:
        typedef void (*Destructor_t)(void*);

    private:
        pthread_key_t m_data;

    public:
        /// create a key that can be used to identify per-thread specific
        /// objects
        /**
         *  @param  destruct    destructor which is called on any non-null
         *                      data when this key is destroyed
         */
        int create(Destructor_t destruct = 0);

        /// destroy the key, call destructor on data if it is set and data
        /// is not null
        int destroy();

        /// return the data associated with this key that belongs to this thread
        void* getSpecific();

        /// set this threads data in the box associated with this key
        int setSpecific( void* value );
};


}















#endif // KEY_H_

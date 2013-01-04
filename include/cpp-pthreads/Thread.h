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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/Thread.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_THREAD_H_
#define CPP_PTHREADS_THREAD_H_

#include <cpp-pthreads/sizes.h>
#include <sched.h>

namespace pthreads
{


template <class T>
void* callCallable( void* obj )
{
    (*static_cast<T*>(obj))();
    return obj;
}

/// interface for a thread
class Thread
{
    public:
        typedef void *(*routine_t)(void*);
        class Attr;

    private:
        char m_data[ sizeOf::pthread ];

    public:
        /// start a new thread storing the id in m_data
        int launch( routine_t start, void* arg );

        /// join a thread, calling thread blocks until this thread has exited
        /**
         *  @see pthread_join
         */
        int join( void** value_ptr=0 );

        /// detach a thread, the thread will be destroyed when it exits
        /**
         *  @see pthread_detach
         */
        int detach();

        /// cancel this thread
        /**
         *  @see pthread_cancel
         */
        int cancel();

        /// send a signal to the thread
        int kill( int sig );

        /// calls pthread_equal
        bool operator==( const Thread& other );

        /// terminates the calling thread
        /**
         *  @see pthread_exit
         */
        static void exit( void* value_ptr );

        /// get a reference to the calling thread itself
        static Thread self();

        /// create a thread from a callable object, i.e. functor, the return
        /// value is obj itself so it should provide access to any result
        template <class T>
        static Thread create( T* obj )
        {
            return Thread( callCallable<T>, obj );
        }
};





}



#endif // THREAD_H_

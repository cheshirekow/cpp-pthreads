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
 *  @file   include/cpp-pthreads/Thread.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  Definition of Thread class
 */

#ifndef CPP_PTHREADS_THREAD_H_
#define CPP_PTHREADS_THREAD_H_

#include <cpp-pthreads/Attr.h>
#include <pthread.h>

namespace pthreads
{


/// function which invokes a callable object when that object is passed
/// to launch a thread
template <class T>
void* callCallable( void* obj )
{
    (*static_cast<T*>(obj))();
    return obj;
}

/// A thread... presumably you know what this is
class Thread
{
    public:
        /// type of a function which the thread will invoke
        typedef void *(*routine_t)(void*);

    private:
        pthread_t m_data;

    public:
        /// start a new thread storing the id in m_data
        int launch( routine_t start, void* arg=0 );

        /// start a new thread using the specified attributes
        int launch( const Attr<Thread>& attr, routine_t start, void* arg=0 );

        /// start a new thread which calls the callable object
        template <typename Callable>
        int launch( Callable* obj )
        {
            return launch( callCallable<Callable>, obj );
        }

        /// start a new thread which calls the collable object and has the
        /// specified attributes
        template <typename Callable>
        int launch( const Attr<Thread>& attr, Callable* obj )
        {
            return launch( attr, callCallable<Callable>, obj );
        }

        /// join a thread, calling thread blocks until this thread has exited
        int join( void** value_ptr=0 );

        /// detach a thread, the thread will be destroyed when it exits
        int detach();

        /// cancel this thread
        int cancel();

        /// send a signal to the thread
        int kill( int sig );

        /// calls pthread_equal
        bool operator==( const Thread& other );

        /// terminates the calling thread
        static void exit( void* value_ptr );

        /// get a reference to the calling thread itself
        static Thread self();
};





}



#endif // THREAD_H_

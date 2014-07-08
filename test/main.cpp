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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/test/main.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp_pthreads.h>
#include <iostream>
#include <sstream>
#include <cstdio>

void* routine( void* data )
{
    std::stringstream msg;
    msg << "hello from thread: " << *(int*)(data) << "\n";
    std::cout << msg.str();
    return 0;
}

int main(int argc, char** argv)
{
    using namespace pthreads;
    const int nThreads = 10;
    Thread threads[nThreads];
    int    id[nThreads];

    for(int i=0; i < nThreads; i++)
        id[i] = i;

    for(int i=0; i < nThreads; i++)
        threads[i].launch(routine, id+i);

    for(int i=0; i < nThreads; i++)
        threads[i].join();


    Attr<Thread> attr;

    // stream assignment test
    attr << JOINABLE
         << Stack(0,100)
         << DETACHED
         << EXPLICIT
         << GuardSize(100)
         << SYSTEM;

    // safe assignment test
    attr.set( JOINABLE );
    attr.set( GuardSize(100 ) );

    DetachState detach;
    InheritSched inherit;
    attr.get( detach );
    attr.get( inherit );

    int guardsize;
    attr.get( GUARD_SIZE, guardsize );

    attr[DETACH_STATE] = DETACHED;
    attr[INHERIT_SCHED]= INHERIT;

    detach  = attr[DETACH_STATE];
    inherit = attr[INHERIT_SCHED];


    return 0;
}









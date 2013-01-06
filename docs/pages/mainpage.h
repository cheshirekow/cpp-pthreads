/**
 *  @file   mainpage.h
 *  @brief  Starting point for documentation (no code)
 *  @author Joshua Bialkowski (jbialk@mit.edu)
 *  @date   Apr 8, 2011
 *
 *  @mainpage   Documentation
 *
 *  cpp-pthreads is a simple wrapper for pthreads which provides a slightly
 *  more "modern", object oriented C++ interface to pthreads. It doesn't
 *  provide any additional functionality, it simply makes multi-threaded
 *  code slightly more readable in C++.
 *
 *  Attribute objects can be filled using the stream operator. For instance:
 *  @code
    #include <cpp-pthreads.h>
    #include <iostream>

    void* routine()
    {
        std::cout << "Hello\n";
    }

    int main()
    {
        using namespace pthreads;

        const unsigned int stackSize = 100;
        char stack[stackSize];


        Attr<Thread> attr;
        attr << JOINABLE
             << Stack(stack,stackSize)
             << DETACHED
             << EXPLICIT
             << GuardSize(10)
             << SYSTEM;

        Thread  thread;
        thread.launch( attr, routine, 0 );
        thread.join
    }
@endcode
 *
 *  Mutexes are slightly easier to maintain with by using ScopedLocks
 *
 *  @code
     using namespace pthreads;
     Mutex  mutex;

     mutex.init();
     {
         ScopedLock lock(mutex);    ///< locks the mutex

         //...  (Do something)

     } // lock goes out of scope and releases the mutex
 @endcode

 *
 * The cmake script for this library produces a shared library
 * (libcpp-pthreads.so) and a static library (libcpp-pthreads_static.a). The
 * install target for the makescript will install the headers, the libraries,
 * and a cmake find script FindCPPThreads.cmake.
 */









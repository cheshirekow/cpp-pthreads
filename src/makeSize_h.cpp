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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/src/makeSize_h.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <pthread.h>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>

#define WRITE( name ) \
    (*out) << "const uint " #name " = " << sizeof( pthread_##name##_t ) << ";\n";

int main(int argc, char** argv)
{
    printf("Size of:\n");
    printf("--------------------\n");
    printf("            pthread_t: %lu\n",  sizeof(pthread_t));
    printf("       pthread_attr_t: %lu\n",  sizeof(pthread_attr_t));
    printf("      pthread_mutex_t: %lu\n",  sizeof(pthread_mutex_t));
    printf("  pthread_mutexattr_t: %lu\n",  sizeof(pthread_mutexattr_t));
    printf("       pthread_cond_t: %lu\n",  sizeof(pthread_cond_t));
    printf("   pthread_condattr_t: %lu\n",  sizeof(pthread_condattr_t));
    printf("       pthread_once_t: %lu\n",  sizeof(pthread_once_t));
    printf("        pthread_key_t: %lu\n",  sizeof(pthread_key_t));
    printf("     pthread_rwlock_t: %lu\n",  sizeof(pthread_rwlock_t));
    printf(" pthread_rwlockattr_t: %lu\n",  sizeof(pthread_rwlockattr_t));
    printf("   pthread_spinlock_t: %lu\n",  sizeof(pthread_spinlock_t));
    printf("    pthread_barrier_t: %lu\n",  sizeof(pthread_barrier_t));
    printf("pthread_barrierattr_t: %lu\n",  sizeof(pthread_barrierattr_t));


    std::ostream* out = &std::cout;
    std::ofstream outstream;

    if(argc < 2)
        std::cerr << "\n\nno output directory given, wont write sizes.h\n";

    else
    {
        std::string   outfile = std::string(argv[1]) + "/sizes.h";
        outstream.open( outfile.c_str() );
        if( !outstream.is_open() )
            std::cerr << "Failed to open " << outfile << " for writing \n";
        else
            out = &outstream;
    }


(*out) <<
"/*\n"
" *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)\n"
" *\n"
" *  This file is part of cpp-pthreads.\n"
" *\n"
" *  cpp-pthreads is free software: you can redistribute it and/or modify\n"
" *  it under the terms of the GNU General Public License as published by\n"
" *  the Free Software Foundation, either version 3 of the License, or\n"
" *  (at your option) any later version.\n"
" *\n"
" *  cpp-pthreads is distributed in the hope that it will be useful,\n"
" *  but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
" *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
" *  GNU General Public License for more details.\n"
" *\n"
" *  You should have received a copy of the GNU General Public License\n"
" *  along with cpp-pthreads.  If not, see <http://www.gnu.org/licenses/>.\n"
" */\n"
"/**\n"
" *  @file   include/cpp-pthreads/src/size.h\n"
" *\n"
" *  @date   Jan 3, 2013\n"
" *  @author Josh Bialkowski (jbialk@mit.edu)\n"
" *  @brief  \n"
" */\n\n"
"#ifndef CPP_PTHREADS_SIZE_H\n"
"#define CPP_PTHREADS_SIZE_H\n\n\n"
"namespace pthreads {\n"
"namespace sizeOf   {\n"
"\n"
;

(*out) << "typedef unsigned int uint;\n";
(*out) << "const uint pthread = " << sizeof(pthread_t) << ";\n";
WRITE( attr );
WRITE( mutex );
WRITE( mutexattr );
WRITE( cond );
WRITE( condattr );
WRITE( once );
WRITE( key );
WRITE( rwlock );
WRITE( rwlockattr );
WRITE( spinlock );
WRITE( barrier );
WRITE( barrierattr );


(*out) <<
"\n"
"} // namespace sizeOf\n"
"} // namespace pthreads\n\n\n"
"#endif // CPP_PTHREADS_SIZE_H\n"
;



}









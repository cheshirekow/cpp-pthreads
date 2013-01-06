find_package( Threads )

if( THREADS_FOUND )

    add_executable( cpp-pthreads_test 
                        main.cpp )

    target_link_libraries( cpp-pthreads_test
                            cpp-pthreads
                            ${CMAKE_THREAD_LIBS_INIT} )
                            
else()

set( MISSING "" )

if( NOT (THREADS_FOUND) )
    set( MISSING "pthreads" )
endif()

message( WARNING "missing: ${MISSING}" )

endif()
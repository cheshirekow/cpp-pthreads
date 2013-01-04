find_package( Threads )

if( THREADS_FOUND )

    add_library( cpp_pthreads
                    enums.cpp
                    Barrier.cpp
                    BarrierAttr.cpp
                    Condition.cpp
                    ConditionAttr.cpp
                    Key.cpp
                    Mutex.cpp
                    MutexAttr.cpp
                    Thread.cpp
                    ThreadAttr.cpp ) 
                    
    add_dependencies( cpp_pthreads do_makeSize_h ) 

    install( TARGETS cpp_pthreads 
                RUNTIME DESTINATION bin
                LIBRARY DESTINATION lib
                ARCHIVE DESTINATION lib )
else()

set( MISSING "" )

if( NOT (THREADS_FOUND) )
    set( MISSING "pthreads" )
endif()

message( WARNING "missing: ${MISSING}" )

endif()
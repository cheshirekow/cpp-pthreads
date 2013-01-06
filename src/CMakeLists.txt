find_package( Threads )

if( THREADS_FOUND )

    set( LIB_FILES
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

    add_library( cpp-pthreads SHARED
                    ${LIB_FILES} )
                    
    add_library( cpp-pthreads_static STATIC
                    ${LIB_FILES} )
                    
    install( TARGETS cpp-pthreads cpp-pthreads_static
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
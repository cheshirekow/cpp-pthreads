find_package( Threads )

if( THREADS_FOUND )

    add_executable( makeSize_h
                    makeSize_h.cpp )
                    
    target_link_libraries( makeSize_h
                            ${CMAKE_THREAD_LIBS_INIT} )
                            
    add_custom_command( 
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp-pthreads/sizes.h
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/makeSize_h
                ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp-pthreads
        DEPENDS makeSize_h )

    add_custom_target( do_makeSize_h DEPENDS 
        ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp-pthreads/sizes.h  )
         
    add_library( cpp_pthreads
                    enums.cpp
                    RefCount.cpp
                    Mutex.cpp
                    Condition.cpp
                    ConditionAttr.cpp
                    Key.cpp
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
set(LIBRARY_SOURCES
    enums.cc
    barrier.cc
    barrier_attr.cc
    condition.cc
    condition_attr.cc
    key.cc
    mutex.cc
    mutex_attr.cc
    thread.cc
    thread_attr.cc)

add_library(cpp_pthreads_static STATIC ${LIBRARY_SOURCES})
add_library(cpp_pthreads_shared SHARED ${LIBRARY_SOURCES})

set_target_properties(
  cpp_pthreads_static
  cpp_pthreads_shared
  PROPERTIES OUTPUT_NAME cpp_pthreads)
                
install(TARGETS 
  cpp_pthreads_static
  cpp_pthreads_shared
  EXPORT CPP_PTHREADS_TARGETS
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib )

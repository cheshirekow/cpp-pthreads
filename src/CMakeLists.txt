find_package(Threads)

set(LIBRARY_SOURCES
    enums.cpp
    Barrier.cpp
    BarrierAttr.cpp
    Condition.cpp
    ConditionAttr.cpp
    Key.cpp
    Mutex.cpp
    MutexAttr.cpp
    Thread.cpp
    ThreadAttr.cpp)

if(THREADS_FOUND)
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
  else()

  if(NOT (THREADS_FOUND))
    message(WARNING "missing pthreads, wont build cpp_pthreads")
  endif()
endif()
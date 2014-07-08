if(THREADS_FOUND)
  add_executable(cpp_pthreads_test main.cpp )
  target_link_libraries(cpp_pthreads_test
                        cpp_pthreads_static
                        ${CMAKE_THREAD_LIBS_INIT})
  add_test(cpp_pthreads_test cpp_pthreads_test)
endif()
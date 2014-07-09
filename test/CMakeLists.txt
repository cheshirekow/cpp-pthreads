set(LIBS
  cpp_pthreads_static
  gtest
  gtest_main
  pthread)
  
macro(cc_test TEST_NAME)
  add_executable(${TEST_NAME} ${ARGN})
  target_link_libraries(${TEST_NAME} ${LIBS})
  add_test(${TEST_NAME} ${TEST_NAME})
endmacro()

cc_test(launch_join_test launch_join.cpp) 
cc_test(attr_api_test attr_api.cpp)
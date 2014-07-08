cmake_minimum_required(VERSION 2.8)

# defines the project name
project (cpp_pthreads)
set(${CMAKE_PROJECT_NAME}_VERSION_MAJOR 0)
set(${CMAKE_PROJECT_NAME}_VERSION_MINOR 1)
set(${CMAKE_PROJECT_NAME}_VERSION_BUGFIX 0)

set(VERSION_STRING "${${CMAKE_PROJECT_NAME}_VERSION_MAJOR}")
set(VERSION_STRING "${VERSION_STRING}.${${CMAKE_PROJECT_NAME}_VERSION_MINOR}")
set(VERSION_STRING "${VERSION_STRING}.${${CMAKE_PROJECT_NAME}_VERSION_BUGFIX}")

# adds the project-specific cmake module directory cmake/Modules to the cmake
# search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# find pthreads
find_package(Threads)

# add the src/ subdirectory to the list of directories cmake processes
include_directories(include)

enable_testing()
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)

# configure the doxygen configuration
configure_file( 
    "${PROJECT_SOURCE_DIR}/doxy.config.in"
    "${PROJECT_BINARY_DIR}/doxy.config" 
    )

# use Jan Woetzel's doxygen doc target
include("TargetDoc" OPTIONAL)

install(EXPORT CPP_PTHREADS_TARGETS
  DESTINATION share/cmake/
  FILE cpp_pthreads_targets.cmake )

configure_file(
  cpp_pthreads-config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/cpp_pthreads-config.cmake 
  @ONLY)


install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cpp_pthreads-config.cmake
  DESTINATION share/cmake/)
    
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}-version.cmake 
  VERSION ${VERSION_STRING} 
  COMPATIBILITY SameMajorVersion)
  
configure_file(
  cpp_pthreads.pc.in
  ${CMAKE_CURRENT_BINARY_DIR}/cpp_pthreads.pc 
  @ONLY)
  
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/cpp_pthreads.pc
  DESTINATION lib/pkg-config/)
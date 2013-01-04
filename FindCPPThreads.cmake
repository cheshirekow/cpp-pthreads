# - Try to find CPPThreads
# Once done, this will define
#
#  CPPThreads_FOUND        - system has CPPThreads
#  CPPThreads_INCLUDE_DIRS - the CPPThreads include directories
#  CPPThreads_LIBRARIES    - link these to use CPPThreads

include(LibFindMacros)

libfind_package( CPPThreads Threads )

# include dir
find_path(CPPThreads_INCLUDE_DIR
  NAMES cpp-pthreads.h
)

#library
libfind_library(CPPThreads cpp_pthreads)

# Set the include dir variables and the libraries and let libfind_process do the rest.
# NOTE: Singular variables for this library, plural for libraries this this lib depends on.
set(CPPThreads_PROCESS_INCLUDES CPPThreads_INCLUDE_DIR)
set(CPPThreads_PROCESS_LIBS CPPThreads_LIBRARY ${CMAKE_THREAD_LIBS_INIT})
libfind_process(CPPThreads)


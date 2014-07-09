/*
 *  Copyright (C) 2012 Josh Bialkowski (jbialk@mit.edu)
 *
 *  This file is part of cpp-pthreads.
 *
 *  cpp-pthreads is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  cpp-pthreads is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with cpp-pthreads.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/test/main.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cstdio>
#include <iostream>
#include <sstream>

#include <gtest/gtest.h>
#include <cpp_pthreads.h>

void* routine(void* data) {
  int* id_ptr = static_cast<int*>(data);
  std::stringstream msg;
  msg << "hello from thread: " << (*id_ptr) << "\n";
  std::cout << msg.str();
  return reinterpret_cast<void*>(*id_ptr);
}

TEST(Thread,LaunchJoin) {
  const int nThreads = 10;
  pthreads::Thread threads[nThreads];
  int id[nThreads];

  for (int i = 0; i < nThreads; i++) {
    id[i] = i;
  }

  for (int i = 0; i < nThreads; i++) {
    threads[i].launch(routine, id + i);
  }

  for (int i = 0; i < nThreads; i++) {
    void* result;
    threads[i].join(&result);
    int result_as_int = reinterpret_cast<long long>(result);
    EXPECT_EQ(result_as_int, i);
  }
}


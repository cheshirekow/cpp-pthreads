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

TEST(Attr,SimpleCompileTest) {
  using namespace pthreads;
  Attr<Thread> attr;

  // stream assignment test
  attr << JOINABLE << Stack(0, 100) << DETACHED << EXPLICIT << GuardSize(100)
       << SYSTEM;

  // safe query test
  DetachState detach;
  InheritSched inherit;
  EXPECT_EQ(0, attr.get(detach));
  EXPECT_EQ(0, attr.get(inherit));
  EXPECT_EQ(DETACHED, detach);
  EXPECT_EQ(EXPLICIT, inherit);

  // safe assignment test
  EXPECT_EQ(attr.set(JOINABLE), 0);
  EXPECT_EQ(attr.set(INHERIT), 0);
  EXPECT_EQ(0, attr.get(detach));
  EXPECT_EQ(0, attr.get(inherit));
  EXPECT_EQ(JOINABLE, detach);
  EXPECT_EQ(INHERIT, inherit);

  int guardsize;
  EXPECT_EQ(0, attr.get(GUARD_SIZE, guardsize));
  EXPECT_EQ(100, guardsize);

  // unsafe assignment and query test
  attr[DETACH_STATE] = DETACHED;
  attr[INHERIT_SCHED] = EXPLICIT;
  detach = attr[DETACH_STATE];
  inherit = attr[INHERIT_SCHED];
  EXPECT_EQ(DETACHED, detach);
  EXPECT_EQ(EXPLICIT, inherit);
}


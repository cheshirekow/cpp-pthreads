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
 *  @file   src/Thread.cpp
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp_pthreads/Thread.h>
#include <cpp_pthreads/ThreadAttr.h>
#include <pthread.h>
#include <signal.h>

namespace pthreads {

int Thread::launch(routine_t start, void* arg) {
  pthread_t* thread = &m_data;
  return pthread_create(thread, 0, start, arg);
}

int Thread::launch(const Attr<Thread>& attr_in, routine_t start, void* arg) {
  pthread_t* thread = &m_data;
  const pthread_attr_t* attr = &(attr_in.m_data);
  return pthread_create(thread, attr, start, arg);
}

int Thread::join(void** value_ptr) {
  return pthread_join(m_data, value_ptr);
}

int Thread::detach() {
  return pthread_detach(m_data);
}

int Thread::cancel() {
  return pthread_cancel(m_data);
}

int Thread::kill(int sig) {
  return pthread_kill(m_data, sig);
}

bool Thread::operator==(const Thread& other) {
  return pthread_equal(m_data, other.m_data);
}

void Thread::exit(void* value_ptr) {
  pthread_exit(value_ptr);
}

Thread Thread::self() {
  Thread thread;
  thread.m_data = pthread_self();
  return thread;
}

}


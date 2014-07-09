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
 *  @file   src/Key.cpp
 *
 *  @date   Jan 4, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#include <cpp_pthreads/Key.h>
#include <pthread.h>

namespace pthreads {

int Key::create(Destructor_t destruct) {
  pthread_key_t* key = &m_data;
  return pthread_key_create(key, destruct);
}

int Key::destroy() {
  pthread_key_t* key = &m_data;
  return pthread_key_delete(*key);
}

void* Key::getSpecific() {
  pthread_key_t* key = &m_data;
  return pthread_getspecific(*key);
}

int Key::setSpecific(void* data) {
  pthread_key_t* key = &m_data;
  return pthread_setspecific(*key, data);
}

}  // namespace pthreads


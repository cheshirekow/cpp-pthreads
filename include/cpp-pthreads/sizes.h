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
 *  @file   include/cpp-pthreads/src/size.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_SIZE_H
#define CPP_PTHREADS_SIZE_H


namespace pthreads {
namespace sizeOf   {

typedef unsigned int uint;
const uint pthread = 8;
const uint mutex = 40;
const uint mutexattr = 4;
const uint cond = 48;
const uint condattr = 4;
const uint once = 4;
const uint key = 4;
const uint rwlock = 56;
const uint rwlockattr = 8;
const uint spinlock = 4;
const uint barrier = 32;
const uint barrierattr = 4;

} // namespace sizeOf
} // namespace pthreads


#endif // CPP_PTHREADS_SIZE_H

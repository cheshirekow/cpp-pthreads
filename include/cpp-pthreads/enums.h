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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/enums.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_ENUMS_H_
#define CPP_PTHREADS_ENUMS_H_

namespace pthreads{

enum DetachState
{
    DETACHED=0,
    JOINABLE
};


/// returns pointer to a map from enums to pthread enums (ints)
template <typename Enum>
int* getEnumMap();

/// returns the pthread integer enumerator that corresponds to the
/// specified value
template <typename Enum>
int mapEnum( Enum val )
{
    return getEnumMap<Enum>()[val];
}

}














#endif // ENUMS_H_

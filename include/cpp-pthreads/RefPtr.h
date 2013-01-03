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
 *  @file   /home/josh/Codes/cpp/cpp-pthreads/include/cpp-pthreads/RefPtr.h
 *
 *  @date   Jan 3, 2013
 *  @author Josh Bialkowski (jbialk@mit.edu)
 *  @brief  
 */

#ifndef CPP_PTHREADS_REFPTR_H_
#define CPP_PTHREADS_REFPTR_H_

#include <cpp-pthreads/RefCount.h>

namespace pthreads {

template <class T>
class RefPtr
{
    private:
        T*  m_obj;

        /// increase reference count
        void increment()
        {
            if(!m_obj)
                return;

            static_cast< RefCount* >(m_obj)->reference();
        }

        /// decrease reference count and destroy if last
        void decrement()
        {
            if(!m_obj)
                return;

            if( static_cast< RefCount* >(m_obj)->dereference() )
                delete m_obj;
        }

    public:
        // refptrs of other types are friends
        template <class OT> friend class RefPtr;

        explicit RefPtr( T* obj = 0 ):
            m_obj( obj )
        {
            increment();
        }

        explicit RefPtr( const RefPtr<T>& other )
        {
            m_obj = other.m_obj;
            increment();
        }

        template <class OT>
        RefPtr( const RefPtr<OT>& other )
        {
            decrement();
            m_obj = static_cast<T*>(other.m_obj);
            increment();
        }

        ~RefPtr()
        {
            decrement();
        }

        RefPtr<T>& operator=( const RefPtr<T>& other )
        {
            decrement();
            m_obj = other.m_obj;
            increment();
            return *this;
        }

        template <class OT>
        RefPtr<T>& operator=( const RefPtr<OT>& other )
        {
            decrement();
            m_obj = static_cast<T*>(other.m_obj);
            increment();
            return *this;
        }

        operator bool()
        {
            return m_obj;
        }

        T& operator*()
        {
            return *m_obj;
        }

        T* operator->()
        {
            return m_obj;
        }
};

}















#endif // REFPTR_H_

/* -*- C++ -*- ------------------------------------------------------------

Copyright 2019 Glen Joseph Fernandes
Copyright 2020 Dirk Sandbrink

The Configurable Math Library (CML) is distributed under the terms of the
Boost Software License, v1.0 (see cml/LICENSE for details).

 *-----------------------------------------------------------------------*/

/**
 * A simple default allocator for C++20 and later.
 *
 * CML1 uses std::allocator as the default allocator. However many functions
 * in std::allocator that are used inside the CML library have been deprecated
 * in C++17 and removed in C++20, see https://wg21.link/p0174 and
 * https://wg21.link/p0619.
 *
 * The code is based on boost/core/default_allocator by Glen Joseph Fernandes.
 */

#ifndef default_allocator_h
#define default_allocator_h

#include <new>
#include <type_traits>

namespace cml {
    template<class T>
    struct default_allocator {

        using value_type = T;

        typedef T* pointer;
        typedef const T* const_pointer;

        using reference = typename std::add_lvalue_reference<T>::type;
        using const_reference = typename std::add_lvalue_reference<const T>::type;

        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;

        using propagate_on_container_move_assignment = std::true_type;
        using is_always_equal = std::true_type;

        template<class U>
        struct rebind {
            using other = default_allocator<U>;
        };

        default_allocator() = default;

        constexpr std::size_t max_size() const noexcept {
            return static_cast<std::size_t>(-1) / (2 < sizeof(T) ? sizeof(T) : 2);
        }

        T* allocate(std::size_t n) {
            if (n > max_size()) {
                throw std::bad_alloc();
            }
            return static_cast<T*>(::operator new(sizeof(T) * n));
        }

        void deallocate(T* p, std::size_t) {
            ::operator delete(p);
        }

        template<class U, class V>
        void construct(U* p, const V& v) {
            ::new(p) U(v);
        }

        template<class U>
        void destroy(U* p) {
            p->~U();
            (void)p;
        }
    };
}

#endif
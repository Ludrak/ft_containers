#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

#include <vector>

// /* --- Helper Class --- */
//
// template<class T, T v>
// struct integral_constant
// {
//     static const T              value;
//     typedef T                   value_type;
//     typedef integral_constant   type;
//     operator                    value_type() const;
// };
//
// typedef integral_constant<bool, true>   true_type;
// typedef integral_constant<bool, false>  false_type;
//
//
// /* --- Helper Traits --- */
//
// template<bool B, class T = void>
// struct  enable_if {};
// template<class T> struct  enable_if<true, T> { typedef T   type; };
//
//
// /* --- Primary Classification Traits --- */
//
// template<class T> struct is_integral                        : public false_type {};
// template<>        struct is_integral<bool>                  : public true_type {};
// template<>        struct is_integral<char>                  : public true_type {};
// template<>        struct is_integral<signed char>           : public true_type {};
// template<>        struct is_integral<unsigned char>         : public true_type {};
// template<>        struct is_integral<wchar_t>               : public true_type {};
// template<>        struct is_integral<char16_t>              : public true_type {};
// template<>        struct is_integral<char32_t>              : public true_type {};
// template<>        struct is_integral<short>                 : public true_type {};
// template<>        struct is_integral<unsigned short>        : public true_type {};
// template<>        struct is_integral<int>                   : public true_type {};
// template<>        struct is_integral<unsigned int>          : public true_type {};
// template<>        struct is_integral<long>                  : public true_type {};
// template<>        struct is_integral<unsigned long>         : public true_type {};
// template<>        struct is_integral<long long>             : public true_type {};
// template<>        struct is_integral<unsigned long long>    : public true_type {};
//
// template<class Iterator, class T = void>
// struct is_iterator
// {
//     static const bool   value = false;
// };
//
// template<class Iterator>
// struct is_iterator<Iterator>
// {
//     typedef typename ft::iterator_traits<Iterator>::iterator_category it;
//     static const bool   value = true;
// };

# include <stdexcept>
# include "iterator_traits.hpp"

/* This was all originaly implemented in C++11 however subject imposes to rewrite it */
namespace ft
{
    /* --- Helper Class --- */

    template<class T, T v>
    struct integral_constant
    {
        static const T              value = v;
        typedef T                   value_type;
        typedef integral_constant   type;
        operator                    value_type() const { return value; }
    };

    typedef integral_constant<bool, true>   true_type;
    typedef integral_constant<bool, false>  false_type;

    /* --- Helper Traits --- */

    template<bool B, class T = void>
    struct  enable_if {};

    template<class T>
    struct  enable_if<true, T> { typedef T   type; };


    template <class T, class U>
    struct is_same : public false_type {};
    
    template <class T>
    struct is_same<T, T> : public true_type {};

    /* --- Primary Classification Traits --- */

    template<class T> struct is_integral                        : public false_type {};
    template<>        struct is_integral<bool>                  : public true_type {};
    template<>        struct is_integral<char>                  : public true_type {};
    template<>        struct is_integral<signed char>           : public true_type {};
    template<>        struct is_integral<unsigned char>         : public true_type {};
    template<>        struct is_integral<wchar_t>               : public true_type {};
    template<>        struct is_integral<char16_t>              : public true_type {};
    template<>        struct is_integral<char32_t>              : public true_type {};
    template<>        struct is_integral<short>                 : public true_type {};
    template<>        struct is_integral<unsigned short>        : public true_type {};
    template<>        struct is_integral<int>                   : public true_type {};
    template<>        struct is_integral<unsigned int>          : public true_type {};
    template<>        struct is_integral<long>                  : public true_type {};
    template<>        struct is_integral<unsigned long>         : public true_type {};
    template<>        struct is_integral<long long>             : public true_type {};
    template<>        struct is_integral<unsigned long long>    : public true_type {};


    template<class Iterator, class T = void>
    struct is_iterator : public false_type 
    {
    };

    template<typename T>
    struct is_iterator<
    T, 
    typename ft::enable_if<!ft::is_same<typename ft::iterator_traits<T>::value_type, void>::value>::type
    >
    : public true_type
    {
    };
}

#endif // TYPE_TRAITS_HPP
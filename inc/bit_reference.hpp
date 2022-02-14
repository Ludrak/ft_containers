
#ifndef BIT_REFERENCE_HPP
# define BIT_REFERENCE_HPP

#include "type_traits.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
    typename ft::enable_if< is_iterator<InputIterator1>::value && is_iterator<InputIterator2>::value, bool >::type
    equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return (false);
            first1++;
            first2++;
        }
       return (true);
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    typename ft::enable_if< is_iterator<InputIterator1>::value && is_iterator<InputIterator2>::value, bool >::type
	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return (false);
            first1++;
            first2++;
        }
        return (true);
    }
}

#endif
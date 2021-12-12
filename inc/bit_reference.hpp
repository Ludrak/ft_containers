
#ifndef BIT_REFERENCE_HPP
# define BIT_REFERENCE_HPP

#include "type_traits.hpp"

namespace ft
{
	template <class InputIterator1, class InputIterator2>
    bool    equal(
        typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type  first1,
		InputIterator1                                                                      last1,
		typename ft::enable_if< is_iterator<InputIterator2>::value, InputIterator2 >::type  first2
        )
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
	bool equal (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type first1,
		InputIterator1                                                                     last1,
		typename ft::enable_if< is_iterator<InputIterator2>::value, InputIterator2 >::type first2,
		BinaryPredicate                                                                    pred
        )
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
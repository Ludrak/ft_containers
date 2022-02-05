
#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

#include "type_traits.hpp"
#include <algorithm>

namespace ft
{
    template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (
		typename ft::enable_if< is_iterator<InputIterator1>::value, InputIterator1 >::type  first1,
		InputIterator1  																	last1,
		typename ft::enable_if< is_iterator<InputIterator2>::value, InputIterator2 >::type  first2,
        InputIterator2																		last2
		)
	{
        while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
    }   
}

#endif // ALGORITHM_HPP

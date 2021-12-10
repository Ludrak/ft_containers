
#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;
        T1          first;
        T2          second;

        pair() : first(), second() { }

        pair(T1 const& t1, T2 const& t2) : first(t1), second(t2) { }

        template <class U1, class U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second) { }

        
        pair&       operator=(pair const& p) {
            first = p.first;
            second = p.second;
            return *this;
        }
        
        // REVIEW std::__is_nothrow_swappable ? 
        void        swap(pair& p) 
        {
            /* swap first */
            first_type first_buf = first;
            first = p.first;
            p.first = first_buf;
            /* swap second */
            second_type second_buf = second;
            second = p.second;
            p.second = second_buf;
        }
    };

    // REVIEW std::__unwrap_ref_decay ? (pair<std::__unwrap_ref_decay<T1>::type, __unwrap_ref_decay<T2>::type>)
    template <class T1, class T2>
    pair<T1, T2>
    make_pair(T1& t1, T2& t2)
    {
        return pair<T1, T2>(static_cast<T1&>(t1), static_cast<T2&>(t2));
    };
}

#endif // UTILITY_HPP
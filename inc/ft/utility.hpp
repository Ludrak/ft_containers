
#ifndef UTILITY_HPP
# define UTILITY_HPP

// template<class T1, class T2>
// struct pair
// {
//     typedef T1  first_type;
//     typedef T2  second_type;
//     T1          first;
//     T2          second;
//
//     pair();
//     pair(T1 const& t1, T2 const& t2);
//     template <class U1, class U2>
//     pair(const pair<U1, U2>& p);
//  
//     pair&       operator=(pair const& p);
//     void        swap(pair& p);
// };
//
// template <class T1, class T2>
// pair<T1, T2> make_pair(T1& t1, T2& t2);

# include "functionnal_base.hpp"

namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        typedef T1  first_type;
        typedef T2  second_type;
        T1          first;
        T2          second;

        pair() : first(), second() 
        {}

        pair(T1 const& t1, T2 const& t2) : first(t1), second(t2)
        {}

        template <class U1, class U2>
        pair(const pair<U1, U2>& p) : first(p.first), second(p.second)
        {}

        
        pair&       operator=(pair const& p)
        {
            first = p.first;
            second = p.second;
            return *this;
        }
        
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

    template <class T1, class T2>bool operator==(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
        return (x.first == y.first);
    }

    template <class T1, class T2> bool operator!=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
        return (!(x == y));
    }

    template <class T1, class T2> bool operator< (const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
        return x.first < y.first;
    }

    template <class T1, class T2> bool operator> (const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
         return (y < x);
    }

    template <class T1, class T2> bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
        return (!(x < y));
    }

    template <class T1, class T2> bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
    {
        return (!(y < x));
    }

    template <class T1, class T2>
    void swap(pair<T1, T2>& x, pair<T1, T2>& y)
    {
        x.swap(y);
    }



    template <class T1, class T2>
    pair<T1, T2>    make_pair(T1 t1, T2 t2)
    {
        return pair<T1, T2>(t1, t2);
    };
}

#endif // UTILITY_HPP
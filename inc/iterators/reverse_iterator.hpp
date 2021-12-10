
#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator : public iterator<typename iterator_traits<Iterator>::iterator_category,
                                             typename iterator_traits<Iterator>::value_type,
                                             typename iterator_traits<Iterator>::difference_type,
                                             typename iterator_traits<Iterator>::pointer,
                                             typename iterator_traits<Iterator>::reference>
    {
        public:
            // /*  TRAITS
            // *   ======
            // */
            typedef Iterator                                                    iterator_type;
            typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
            typedef typename iterator_traits<iterator_type>::reference          reference;
            typedef typename iterator_traits<iterator_type>::pointer            pointer;



            // /*  CONSTRUCTORS
            // *   ============
            // */
            reverse_iterator();
            explicit                reverse_iterator(iterator_type x) : _current(x) { };
            template <class U>      reverse_iterator(const reverse_iterator<U>& u) : _current(u) { };



            // /*  MEMBER FUNCTIONS
            // *   ================
            // */
            iterator_type           base() const
            {
                return (this->_current);
            }
        


            // /*  OPERATORS
            // *   =========
            // */

            /* Equal Operator */
            template <class U>
            reverse_iterator&       operator=(const reverse_iterator<U>& u)
            {
                this->_current = u.base();
            }


            /* Increment Operators */
            reverse_iterator&       operator++() const
            {
                return (this->_current--);
            }

            reverse_iterator        operator++(int) const
            {
                return(Iterator(this->_current--(0)));
            }

            reverse_iterator&       operator--() const
            {
                return (this->_current++);
            }

            reverse_iterator        operator--(int) const
            {
                return(Iterator(this->_current++(0)));
            }


            /* Pointer Operators  */
            reference               operator*() const
            {
                return (*Iterator(this->_current));
            }

            pointer                 operator->() const
            {
                return (&(*this->operator*()));
            }


            /* Arithmetic Operators */
            reverse_iterator        operator+(difference_type n) const
            {
                return (reverse_iterator(this->_current - n));
            }

            reverse_iterator&       operator+=(difference_type n) const
            {
                return (this->_current -= n);
            }

            reverse_iterator        operator-(difference_type n) const
            {
                return (reverse_iterator(this->_current + n));
            }

            reverse_iterator&       operator-=(difference_type n) const
            {
                return (this->_current += n);
            }


            /* Index Operator */
            reference               operator[](difference_type n) const
            {
                return (*(this + n));
            }



            /*  COMPARATORS
            *   ===========
            */

            template <class U>
            bool                    operator==(const reverse_iterator<U> &rhs) const
            {
                return (this->_current == rhs.base());
            }

            
            template <class U>
            bool                    operator!=(const reverse_iterator<U> &rhs) const
            {
                return (this->_current != rhs.base());
            }

            
            template <class U>
            bool                    operator<(const reverse_iterator<U> &rhs) const
            {
                return (this->_current > rhs.base());
            }

            
            template <class U>
            bool                    operator<=(const reverse_iterator<U> &rhs) const
            {
                return (this->_current >= rhs.base());
            }

            
            template <class U> 
            bool                    operator> (const reverse_iterator<U> &rhs) const
            {
                return (this->_current < rhs.base());
            }

            
            template <class U>
            bool                    operator>=(const reverse_iterator<U> &rhs) const
            {
                return (this->_current <= rhs.base()); 
		    }

        protected:
            iterator_type   _current;
    };

}

#endif
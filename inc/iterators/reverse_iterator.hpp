#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "type_traits.hpp"

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
            
            explicit                reverse_iterator(iterator_type x) : _base(x) { };
            
            reverse_iterator(const reverse_iterator<iterator_type>& u) : _base(u._base) { };



            // /*  MEMBER FUNCTIONS
            // *   ================
            // */
            iterator_type           base() const
            {
                return (this->_base);
            }
        


            // /*  OPERATORS
            // *   =========
            // */

            /* Equal Operator */
            template <class U>
            reverse_iterator&       operator=(const reverse_iterator<U>& u)
            {
                this->_base = u.base();
            }


            /* Increment Operators */
            reverse_iterator&       operator++()
            {
                this->_base.operator--();
                return (*this);
            }

            reverse_iterator        operator++(int)
            {
                return(reverse_iterator(this->_base.operator--(0)));
            }

            reverse_iterator&       operator--()
            {
                this->_base.operator++();
                return (*this);
            }

            reverse_iterator        operator--(int)
            {
                return(reverse_iterator(this->_base.operator++(0)));
            }


            /* Pointer Operators  */
            reference               operator*() const
            {
                return (*iterator_type(this->_base));
            }

            pointer                 operator->() const
            {
                return (&(*this->operator*()));
            }


            /* Arithmetic Operators */
            reverse_iterator        operator+(difference_type n) const
            {
                return (reverse_iterator(this->_base - n));
            }

            reverse_iterator&       operator+=(difference_type n) const
            {
                return (this->_base -= n);
            }

            reverse_iterator        operator-(difference_type n) const
            {
                return (reverse_iterator(this->_base + n));
            }

            reverse_iterator&       operator-=(difference_type n) const
            {
                return (this->_base += n);
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
                return (this->_base == rhs.base());
            }

            
            template <class U>
            bool                    operator!=(const reverse_iterator<U> &rhs) const
            {
                return (this->_base != rhs.base());
            }

            
            template <class U>
            bool                    operator<(const reverse_iterator<U> &rhs) const
            {
                return (this->_base > rhs.base());
            }

            
            template <class U>
            bool                    operator<=(const reverse_iterator<U> &rhs) const
            {
                return (this->_base >= rhs.base());
            }

            
            template <class U> 
            bool                    operator> (const reverse_iterator<U> &rhs) const
            {
                return (this->_base < rhs.base());
            }

            
            template <class U>
            bool                    operator>=(const reverse_iterator<U> &rhs) const
            {
                return (this->_base <= rhs.base()); 
		    }

        protected:
            iterator_type   _base;
    };

}

#endif
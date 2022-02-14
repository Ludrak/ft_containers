#ifndef STACK_HPP
# define STACK_HPP

// template <class T, class Container = vector<T> >
// class stack;
//
// /*       TYPES
//  *       =====
//  */
// typedef Container                                container_type;
// typedef typename container_type::value_type      value_type;
// typedef typename container_type::reference       reference;
// typedef typename container_type::const_reference const_reference;
// typedef typename container_type::size_type       size_type;
//
//
//
// /*       CONSTRUCTORS / DESTRUCTORS
//  *       ==========================
//  */
// explicit stack (const container_type& ctnr = container_type());
//
// ~stack();
//
//
//
// /*       MEMBER_FUNCTIONS
//  *       ================
//  */
//
// bool            empty() const;
//
// size_type       size() const;
//
// reference       top();
// const_reference top() const;
//
// void            push(const value_type& x);
// void            push(value_type& x);
//
// void            pop();
//
//
//
// /*       OPERATORS
//  *       =========
//  */
// stack&          operator= (const stack& q) = default;
// stack&          operator= (stack& q) = default;
//
//
//
// /*       RELATIONAL OPERATORS
//  *       ====================
//  */
// friend bool     operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
// friend bool     operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
// friend bool     operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
// friend bool     operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
// friend bool     operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
// friend bool     operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
//
//
//
// /*       PROTECTED_FIELDS
//  *       ================
//  */
// container_type c;


# include "vector.hpp"
# include <stack>

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
        public:
            /*  TYPES
             *  =====
             */
            typedef Container                                container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;



            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */

            explicit stack (const container_type& ctnr = container_type())
            : _container(ctnr)
            { }

            ~stack()
            {
            }



            /*  MEMBER_FUNCTIONS
             *  ================
             */
            //empty
            bool            empty() const
            {
                return (this->_container.empty());
            }

            //size
            size_type       size() const
            {
                return (this->_container.size());
            }

            //top
            reference       top()
            {
                return (*this->_container.rbegin());
            }
            const_reference top() const
            {
                return (*this->_container.rbegin());
            }

            //push
            void            push(const value_type& x)
            {
                this->_container.push_back(x);
            }
            void            push(value_type& x)
            {
                this->_container.push_back(x);
            }
            
            //pop
            void            pop()
            {
                this->_container.erase(--this->_container.end());
            }



            /*  OPERATORS
             *  =========
             */
            stack&          operator= (const stack& q)
            {
                this->_container = container_type(q._container);
                return (*this);
            }

            stack&          operator= (stack& q)
            {
                this->_container = container_type(q._container);
                return (*this);
            }

            friend bool operator==(stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                    return (x._container == y._container);
            }

            friend bool operator< (stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                return (x._container < y._container);
            }

            friend bool operator!=(stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                return !(x == y);
            }

            friend bool operator> (stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                return y < x;
            }

            friend bool operator>=(stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                return !(x < y);
            }

            friend bool operator<=(stack<T, Container> const& x, stack<T, Container> const& y) 
            {
                return !(y < x);
            }
            
        protected:
            container_type _container;
    };
}

#endif // STACK_HPP
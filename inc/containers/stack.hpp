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

            explicit stack (const container_type& ctnr = container_type());

            ~stack();



            /*  MEMBER_FUNCTIONS
             *  ================
             */
            //empty
            bool            empty() const;

            //size
            size_type       size() const;

            //top
            reference       top();
            const_reference top() const;

            //push
            void            push(const value_type& x);
            void            push(value_type& x);
            
            //pop
            void            pop();



            /*  OPERATORS
             *  =========
             */
            stack&          operator= (const stack& q) = default;
            stack&          operator= (stack& q) = default;



            /*  RELATIONAL OPERATORS
             *  ====================
             */
            friend bool     operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
            friend bool     operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
            friend bool     operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
            friend bool     operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
            friend bool     operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
            friend bool     operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        
        protected:
            container_type c;
    };
}

#endif // STACK_HPP

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
    template<class T, typename Allocator = std::allocator<T> >
    class vector
    {
        public:

            /*  TYPES
             *  =====
             */           
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ptrdiff_t                                   difference_type;
			typedef	size_t                                      size_type;




            /*  ITERATORS
             *  =========
             */

            class iterator
            {
                public:
                    typedef ptrdiff_t							difference_type;
					typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
                    ft::random_access_iterator_tag              iterator_category;
                // TODO implement unimplemented operators
            };

            class const_iterator
            {
                public:
                    typedef ptrdiff_t							difference_type;
					typedef T									value_type;
					typedef value_type*							pointer;
					typedef value_type&							reference;
                    ft::random_access_iterator_tag              iterator_category;
                // TODO implement unimplemented operators
            };

            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;




            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */  

            explicit vector(const allocator_type& alloc = allocator_type());
           
            explicit vector(size_type n, const value_type& val = value_type(),
                                                    const allocator_type& alloc = allocator_type());
           
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
           
            vector(const vector& x);

            virtual ~vector(void);





            /*  MEMBER FUNCTIONS
             *  ================
             */

            //begin
            iterator                begin();
            const_iterator          begin() const;

            //end
            iterator                end();
            const_iterator          end() const;

            //rbegin
            reverse_iterator        rbegin();
            const_reverse_iterator  rbegin() const;

            //rend
            reverse_iterator        rend();
            const_reverse_iterator  rend() const;
            
            //back
            reference               back();
            const_reference         back() const;

            //front
            reference               front();
            const_reference         front() const;

            //at
            reference               at (size_type n);
            const_reference         at (size_type n) const;

            //assign
            void                    assign (size_type n, const value_type& val);
            template <class InputIterator>
            void                    assign (InputIterator first, InputIterator last);

            //capacity
            size_type               capacity() const;

            //clear
            void                    clear();

            //empty
            bool                    empty() const;

            //erase
            iterator                erase(iterator position);
            iterator                erase(iterator first, iterator last);

            //get_allocator
            allocator_type          get_allocator() const;

            //insert
            iterator                insert(iterator position, const value_type& val);
            void                    insert(iterator position, size_type n, const value_type& val);
            template <class InputIterator>
            void                    insert(iterator position, InputIterator first, InputIterator last);

            //max_size
            size_type               max_size() const;

            //pop_back
            void                    pop_back();

            //push_back
            void                    push_back(const value_type& val);

            //reserve
            void                    reserve(size_type n);

            //resize
            void                    resize(size_type n, value_type val = value_type());

            //size
            size_type               size() const;

            //swap
            void                    swap(vector& x);




            /*  OPERATORS
             *  =========
             */

            vector&                 operator=(const vector& x);

            reference               operator[](size_type n);
            const_reference         operator[](size_type n) const;




            /* NON MEMBER OPERATORS FRIENDS
            *  ============================
            */
            friend bool             operator== (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
            friend bool             operator!= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
            friend bool             operator<  (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
            friend bool             operator<= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
            friend bool             operator>  (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
            friend bool             operator>= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);


            /* NON MEMBER OVERLOADS FRIENDS
            *  ============================
            */
           
            friend void             swap (vector<T, Allocator>& x, vector<T, Allocator>& y);



            /* PRIVATE
            *  =======
            */
        private:

            value_type*     _data;
            size_type       _capacity;
        	size_type       _size;
            allocator_type  _allocator;

    };
}

#endif // VECTOR_HPP

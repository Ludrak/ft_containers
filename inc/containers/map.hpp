#ifndef MAP_HPP
# define MAP_HPP

// template<
// class Key,
// class T,
// class Compare = ft::less<Key>,
// class Allocator = std::allocator<ft::pair<const Key, T> >
// > 
// class map;
//
// /*       TYPES
//  *       =====
//  */
// typedef Key                                      key_type;
// typedef T                                        mapped_type;
// typedef ft::pair<const key_type, mapped_type>    value_type;
// typedef Compare                                  key_compare;
// typedef Allocator                                allocator_type;
// typedef typename allocator_type::reference       reference;
// typedef typename allocator_type::const_reference const_reference;
// typedef typename allocator_type::pointer         pointer;
// typedef typename allocator_type::const_pointer   const_pointer;
// typedef typename allocator_type::size_type       size_type;
// typedef typename allocator_type::difference_type difference_type;

// class value_compare : public binary_function<value_type, value_type, bool>
// {
//     private:
//         friend class map;
//     protected:
//         key_compare comp;
//         value_compare(key_compare c)
//     public:
//         bool operator()(const value_type& x, const value_type& y) const
// };
//
//
//
// /*       ITERATORS
//  *       =========
//  */
// class                                            iterator;
// class                                            const_iterator;
// typedef ft::reverse_iterator<iterator>           reverse_iterator;
// typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
//
//
//
// /*       CONSTRUCTORS / DESTRUCTORS
//  *       ==========================
//  */
// explicit map (const key_compare& comp = key_compare(), 
//                                             const allocator_type& alloc = allocator_type());
// template <class InputIterator>
// map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
//                                             const allocator_type& alloc = allocator_type());
// map (const map& x);
// ~map();
//
//
//
// /*       MEMBER FUNCTIONS
//  *       ================
//  */
// iterator                                begin();
// const_iterator                          begin() const;
//
// iterator                                end();
// const_iterator                          end() const;
//
// reverse_iterator                        rbegin();
// const_reverse_iterator                  rbegin() const;
//
// reverse_iterator                        rend();
// const_reverse_iterator                  rend() const;
//
// iterator                                upper_bound(const key_type& k);
// const_iterator                          upper_bound(const key_type& k) const;
//
// iterator                                lower_bound(const key_type& k);
// const_iterator                          lower_bound(const key_type& k) const;
//
// void                                    clear();
//
// size_type                               count(const key_type& k) const;
//
// bool                                    empty() const;
//
// ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
// ft::pair<iterator,iterator>             equal_range(const key_type& k);
//
// void                                    erase(iterator position);
// size_type                               erase(const key_type& k);
// void                                    erase(iterator first, iterator last);
//
// iterator                                find(const key_type& k);
// const_iterator                          find(const key_type& k) const;
//
// allocator_type                          get_allocator() const;
//
// ft::pair<iterator,bool>                 insert(const value_type& val);
// iterator                                insert(iterator position, const value_type& val);
// template <class InputIterator>
// void                                    insert(InputIterator first, InputIterator last);
//
// key_compare                             key_comp() const;
//
// size_type                               max_size() const;
//
// size_type                               size() const;
//
// void                                    swap(map& x);
//
// value_compare                           value_comp() const;
//
//
//
// /*       OPERATORS
//  *       =========
//  */
// map                     operator= (const map& x);
// mapped_type&            operator[](const key_type& k);
//
//
//
// /*       RELATIONNAL OPERATORS
//  *       =====================
//  */
// friend bool             operator==( const map<Key, T, Compare, Allocator>& lhs, 
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
// friend bool             operator!=( const map<Key, T, Compare, Allocator>& lhs,
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
// friend bool             operator< ( const map<Key, T, Compare, Allocator>& lhs,
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
// friend bool             operator<=( const map<Key, T, Compare, Allocator>& lhs,
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
// friend bool             operator> ( const map<Key, T, Compare, Allocator>& lhs,
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
// friend bool             operator>=( const map<Key, T, Compare, Allocator>& lhs,
//                                     const map<Key, T, Compare, Allocator>& rhs );
//
//
//
// /*       NON MEMBER FUNCTIONS
//  *       ====================
//  */
// friend void                             swap (map<Key, T, Compare, Allocator>& x,
//                                                 map<Key, T, Compare, Allocator>& y);




# include "reverse_iterator.hpp"
# include "utility.hpp"

namespace ft
{
    template<
    class Key,
    class T,
    class Compare = ft::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> >
    > 
    class map
    {
        public:

            /*  TYPES
             *  =====
             */
            typedef Key                                      key_type;
            typedef T                                        mapped_type;
            typedef ft::pair<const key_type, mapped_type>    value_type;
            typedef Compare                                  key_compare;
            typedef Allocator                                allocator_type;
            typedef typename allocator_type::reference       reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer         pointer;
            typedef typename allocator_type::const_pointer   const_pointer;
            typedef typename allocator_type::size_type       size_type;
            typedef typename allocator_type::difference_type difference_type;
            
            class value_compare : public binary_function<value_type, value_type, bool>
            {
                private:
                    friend class map;

                protected:
                    key_compare comp;

                    value_compare(key_compare c) : comp(c)
                        { }

                public:
                    bool operator()(const value_type& x, const value_type& y) const
                        { return comp(x.first, y.first); }
            };



            /*  ITERATORS
             *  =========
             */
            class iterator
            {
                public:
                    typedef ptrdiff_t                           difference_type;
					typedef T                                   value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    ft::random_access_iterator_tag              iterator_category;
                // TODO implement unimplemented operators
            };

            class const_iterator
            {
                public:
                    typedef ptrdiff_t                           difference_type;
					typedef T                                   value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    ft::random_access_iterator_tag              iterator_category;
                // TODO implement unimplemented operators
            };

            typedef ft::reverse_iterator<iterator>           reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;



            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */  

            explicit map (const key_compare& comp = key_compare(), 
                                                        const allocator_type& alloc = allocator_type());

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                                                        const allocator_type& alloc = allocator_type());

            map (const map& x);

            ~map();



            /*  MEMBER FUNCTIONS
             *  ================
             */

            //begin
            iterator                                begin();
            const_iterator                          begin() const;

            //end
            iterator                                end();
            const_iterator                          end() const;

            //rbegin
            reverse_iterator                        rbegin();
            const_reverse_iterator                  rbegin() const;

            //rend
            reverse_iterator                        rend();
            const_reverse_iterator                  rend() const;

            //upper_bound
            iterator                                upper_bound(const key_type& k);
            const_iterator                          upper_bound(const key_type& k) const;
            
            //lower_bound
            iterator                                lower_bound(const key_type& k);
            const_iterator                          lower_bound(const key_type& k) const;

            //clear
            void                                    clear();

            //count
            size_type                               count(const key_type& k) const;

            //empty
            bool                                    empty() const;

            //equal_range
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
            ft::pair<iterator,iterator>             equal_range(const key_type& k);

            //erase
            void                                    erase(iterator position);
            size_type                               erase(const key_type& k);
            void                                    erase(iterator first, iterator last);
            
            //find
            iterator                                find(const key_type& k);
            const_iterator                          find(const key_type& k) const;

            //get_allocator
            allocator_type                          get_allocator() const;

            //insert
            ft::pair<iterator,bool>                 insert(const value_type& val);
            iterator                                insert(iterator position, const value_type& val);
            template <class InputIterator>
            void                                    insert(InputIterator first, InputIterator last);
            
            //key_comp
            key_compare                             key_comp() const;

            //max_size
            size_type                               max_size() const;

            //size
            size_type                               size() const;

            //swap
            void                                    swap(map& x);

            //value_comp
            value_compare                           value_comp() const;



            /*  OPERATORS
             *  =========
             */
            map                     operator= (const map& x);

            mapped_type&            operator[](const key_type& k);



            /*  RELATIONNAL OPERATORS
             *  =====================
             */
            friend bool             operator==( const map<Key, T, Compare, Allocator>& lhs, 
                                                const map<Key, T, Compare, Allocator>& rhs );
    
            friend bool             operator!=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs );

            friend bool             operator< ( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs );

            friend bool             operator<=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs );

            friend bool             operator> ( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs );

            friend bool             operator>=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs );



            /*  NON MEMBER FUNCTIONS
             *  ====================
             */
            friend void                             swap (map<Key, T, Compare, Allocator>& x,
                                                            map<Key, T, Compare, Allocator>& y);
    };
}

#endif // MAP_HPP

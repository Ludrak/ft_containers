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


#include <map>
#include <utility>

# include "reverse_iterator.hpp"
# include "utility.hpp"
# include "binary_tree.hpp"

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
					typedef map::value_type                     value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    ft::random_access_iterator_tag              iterator_category;
                
                protected:
                    value_type                                  _value;

                public:
					iterator() : _value(NULL) { }

					iterator(value_type* val) : _value(val) { }
					
                    iterator(const iterator& src) : _value(src._value) { }

					~iterator() {}

                    value_type                          base() const
                    {
                        return (this->_value);
                    }

					iterator							&operator=(const iterator &rhs)
					{
						if ( this != &rhs)
							this->_value = rhs._value;

						return *this;
					}

					reference							operator*(void) const
					{
						return *(this->_value);
					}

					pointer								operator->(void) const
					{
						return (this->_value);
					}
					
					iterator::difference_type			operator+(const iterator & rhs) const
					{
						return (this->_value + rhs._value);
					}
					
					iterator::difference_type			operator-(const iterator & rhs) const
					{
						return (this->_value - rhs._value);
					}
					
					iterator							operator+(difference_type n) const
					{
						return iterator(this->_value + n);
					}
					
					iterator							operator-(difference_type n) const
					{
						return iterator(this->_value - n);
					}
					
					iterator							&operator+=(difference_type n)
					{
						this->_value += n;
						return *this;
					}

					iterator							&operator-=(difference_type n)
					{
						this->_value -= n;
						return *this;
					}

					bool								operator!=(const iterator &rhs) const
                    {
						return (this->_value != rhs._value);
					}

					bool								operator==(const iterator &rhs) const
                    {
						return (this->_value == rhs._value);
					}
					
					iterator			&operator++(void)
					{
						++this->_value;
						return *this;
					}

					iterator			operator++(int)
					{
						iterator copy(*this);
						++this->_value;
						return copy;
					}

					iterator			&operator--(void)
					{
						--this->_value;
						return *this;
					}

					iterator			operator--(int)
					{
						iterator copy(*this);
						--this->_value;
						return copy;
					}
					bool				operator<(const iterator& rhs) const
					{
						return (this->_value < rhs._value);
					}
					
					bool				operator>(const iterator& rhs) const
					{
						return (this->_value > rhs._value);
					}
					
					bool				operator<=(const iterator& rhs) const
					{
						return (this->_value <= rhs._value);
					}
					
					bool				operator>=(const iterator& rhs) const
					{
						return (this->_value >= rhs._value);
					}
            };

            class const_iterator
            {
                public:
                    typedef ptrdiff_t                           difference_type;
					typedef map::value_type                     value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    ft::random_access_iterator_tag              iterator_category;


                protected:
					value_type 		*_value;
					
				public:
					const_iterator() : _value(NULL) {}

					const_iterator(value_type* val) : _value(val) { }
					
					const_iterator(const const_iterator& src) : _value(src._value) { }

					~const_iterator() { }

                    value_type                              base() const
                    {
                        return (this->_value);
                    }

					const_iterator&                         operator=(const const_iterator &rhs)
					{
						if ( this != &rhs)
							this->_value = rhs._value;
					
						return *this;
					}

					reference								operator*(void) const
					{
                        if (this->_value)
						    return *(this->_value);
                        throw std::out_of_range("cannot dereference on null data");
					}

					pointer									operator->(void) const
					{
						return (this->_value);
					}
					
					const_iterator::difference_type			operator+(const const_iterator &rhs) const
					{
						return (this->_value + rhs._value);
					}
					
					const_iterator::difference_type			operator-(const const_iterator &rhs) const
					{
						return (this->_value - rhs._value);
					}
					
					const_iterator							operator+(difference_type n) const
					{
						return const_iterator(this->_value + n);
					}
					
					const_iterator							operator-(difference_type n) const
					{
						return const_iterator(this->_value - n);
					}
					
					const_iterator&                         operator+=(difference_type n)
					{
						this->_value += n;
						return *this;
					}

					const_iterator&                         operator-=(difference_type n)
					{
						this->_value -= n;
						return *this;
					}

					bool									operator!=(const const_iterator &rhs) const
                    {
						return (this->_value != rhs._value);
					}
					
					bool									operator==(const const_iterator &rhs) const
                    {
						return (this->_value == rhs._value);
					}
					const_iterator&                         operator++(void)
					{
						++this->_value;
						return *this;
					}

					const_iterator							operator++(int)
					{
						const_iterator copy(*this);
						++this->_value;
						return copy;
					}

					const_iterator&                         operator--(void)
					{
						--this->_value;
						return *this;
					}

					const_iterator							operator--(int)
					{
						const_iterator cpy(*this);
						--this->_value;
						return cpy;
					}

					bool									operator<(const const_iterator& rhs) const
					{
						return (this->_value < rhs._value);
					}
					
					bool									operator>(const const_iterator& rhs) const
					{
						return (this->_value > rhs._value);
					}
					
					bool									operator<=(const const_iterator& rhs) const
					{
						return (this->_value <= rhs._value);
					}
					
					bool									operator>=(const const_iterator& rhs) const
					{
						return (this->_value >= rhs._value);
					}
            };

            typedef ft::reverse_iterator<iterator>           reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;



            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */  

            explicit map (const key_compare& comp = key_compare(), 
                                                        const allocator_type& alloc = allocator_type())
            : _base(), _alloc(alloc), _key_compare(comp)
            { }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                                                        const allocator_type& alloc = allocator_type());
            // TODO when insert is done

            map (const map& x);

            ~map();



            /*  MEMBER FUNCTIONS
             *  ================
             */

            //begin
            iterator                                begin()
            {
                return (iterator(_base.lowest_bound()));
            }

            const_iterator                          begin() const
            {
                return (const_iterator(_base.lowest_bound()));
            }


            //end
            iterator                                end()
            {
                return (iterator(_base.highest_bound()));
            }

            const_iterator                          end() const
            {
                return (const_iterator(_base.highest_bound()));
            }

            //rbegin
            reverse_iterator                        rbegin()
            {
                return (reverse_iterator(_base.highest_bound()));
            }

            const_reverse_iterator                  rbegin() const
            {
                return (const_reverse_iterator(_base.highest_bound()));
            }

            //rend
            reverse_iterator                        rend()
            {
                return (reverse_iterator(_base.lowest_bound()));
            }

            const_reverse_iterator                  rend() const
            {
                return (const_reverse_iterator(_base.lowest_bound()));
            }

            //upper_bound
            iterator                                upper_bound(const key_type& k)
            {
                return (iterator(_base.upper_bound(k)));
            }

            const_iterator                          upper_bound(const key_type& k) const
            {
                return (const_iterator(_base.upper_bound(k)));
            }
            
            //lower_bound
            iterator                                lower_bound(const key_type& k)
            {
                return (iterator(_base.lower_bound(k)));
            }

            const_iterator                          lower_bound(const key_type& k) const
            {
                return (const_iterator(_base.lower_bound(k)));
            }

            //clear
            void                                    clear()
            {
                
            }

            //count
            size_type                               count(const key_type& k) const;

            //empty
            bool                                    empty() const;

            //equal_range
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
            ft::pair<iterator,iterator>             equal_range(const key_type& k);

            //erase
            void                                    erase(iterator position);
            size_type                               erase(const key_type& k)
            {
                _base.erase(k);
            }

            void                                    erase(iterator first, iterator last);
            
            //find
            iterator                                find(const key_type& k);
            const_iterator                          find(const key_type& k) const;

            //get_allocator
            allocator_type                          get_allocator() const;

            //insert
            ft::pair<iterator,bool>                 insert(const value_type& val)
            {
                _tree_node<value_type>  *occurence;
                if ((occurence = _base.search(val)) != _base.end())
                    return (ft::make_pair(iterator((*occurence)()), false));
                _base.insert(val);
                return (ft::make_pair(iterator(val), false));
            }

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
        private:
            binary_tree<value_type>   _base;
            allocator_type            _alloc;
            key_compare               _key_compare;

 /*         typedef _VSTD::__value_type<key_type, mapped_type>                  __value_type;
            typedef __map_value_compare<key_type, __value_type, key_compare>    __vc;

            typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>, __value_type>::type
                                                                                __allocator_type;
            typedef typename __base::__node_traits                              __node_traits;
            typedef allocator_traits<allocator_type>                            __alloc_traits;
    */

    };
}

#endif // MAP_HPP

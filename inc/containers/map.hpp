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
# include "algorithm.hpp"
# include "bit_reference.hpp"

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

            typedef binary_tree<value_type, allocator_type>  tree_type;
            typedef _tree_node<value_type, allocator_type>   node_type;
            
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

            typedef typename tree_type::iterator                iterator;
            typedef typename tree_type::const_iterator          const_iterator;
            typedef typename tree_type::reverse_iterator        reverse_iterator;
            typedef typename tree_type::const_reverse_iterator  const_reverse_iterator;


            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */  

            explicit map (const key_compare& comp = key_compare(), 
                                                        const allocator_type& alloc = allocator_type())
            : _base(new tree_type()), _alloc(alloc), _key_compare(comp), _value_compare(comp)
            { 

            }

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
                                                        const allocator_type& alloc = allocator_type())
            : _base(new tree_type()), _alloc(alloc), _key_compare(comp), _value_compare(comp)
            {
                this->insert(first, last);
            }

            map (const map& x)
            : _base(new tree_type(*x._base)), _alloc(x._alloc), _key_compare(x._key_compare), _value_compare(x._value_compare)
            { }

            ~map()
            { delete this->_base; }



            /*  MEMBER FUNCTIONS
             *  ================
             */

            //begin
            iterator                                begin()
            {
                return (this->_base->begin());
            }

            const_iterator                          begin() const
            {
                return (this->_base->begin().base());
            }


            //end
            iterator                                end()
            {
                return (this->_base->end());
            }

            const_iterator                          end() const
            {
                return (this->_base->end().base());
            }

            //rbegin
            reverse_iterator                        rbegin()
            {
                return (this->_base->rbegin());
            }

            const_reverse_iterator                  rbegin() const
            {
                if (this->size() == 0)
                    return (ft::reverse_iterator<const_iterator>(this->_base->start())); 
                return (ft::reverse_iterator<const_iterator>(this->_base->highest_bound())); 
            }

            //rend
            reverse_iterator                        rend()
            {
                return (this->_base->rend());
            }

            const_reverse_iterator                  rend() const
            {
                return (ft::reverse_iterator<const_iterator>(this->_base->start())); 
            }

            //upper_bound
            iterator                                upper_bound(const key_type& k)
            {
                return (iterator(_base->upper_bound(ft::make_pair(k, mapped_type()))));
            }

            const_iterator                          upper_bound(const key_type& k) const
            {
                return (const_iterator(_base->upper_bound(ft::make_pair(k, mapped_type()))));
            }
            
            //lower_bound
            iterator                                lower_bound(const key_type& k)
            {
                return (iterator(_base->lower_bound(ft::make_pair(k, mapped_type()))));
            }

            const_iterator                          lower_bound(const key_type& k) const
            {
                return (const_iterator(_base->lower_bound(ft::make_pair(k, mapped_type()))));
            }

            //clear
            void                                    clear()
            {
                delete this->_base;
                this->_base = new tree_type();
                //this->_base->destroy();
                //this->_base = tree_type();
                //std::cout << "new bounds thing: " << this->end().base() << " ; " << this->_base->start()  << std::endl;

            }

            //count
            size_type                               count(const key_type& k) const
            {
                node_type *buf = this->_base->search(ft::make_pair(k, mapped_type()));
                if (!buf || buf == this->_base->end().base() || buf == this->_base->start())
                    return (0);
                return (1); 
            }

            //empty
            bool                                    empty() const
            {
                return (this->_base->empty() );
            }

            //equal_range
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
            {
                return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
            }

            ft::pair<iterator,iterator>             equal_range(const key_type& k)
            {
                return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
            }

            //erase
            void                                    erase(iterator position)
            {
                this->_base->erase(*position);
            }

            size_type                               erase(const key_type& k)
            {
                if (this->find(k) == this->end())
                    return (0);
                this->_base->erase(ft::make_pair(k, mapped_type()));
                return (1);
            }

            void                                    erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    this->erase(first++);
                } 
            }
            
            //find
            iterator                                find(const key_type& k)
            {
                node_type* buf = this->_base->search(ft::make_pair(k, mapped_type()));
                if (!buf || buf == this->_base->end().base() || buf == this->_base->start())
                {
                    return this->end();
                }
                return (iterator(buf));
            }

            const_iterator                          find(const key_type& k) const
            {
                node_type* buf = this->_base->search(ft::make_pair(k, mapped_type()));
                if (!buf || buf == this->_base->end().base() || buf != this->_base->begin().base())
                    return this->end();
                return (const_iterator(buf));
            }

            //get_allocator
            allocator_type                          get_allocator() const
            {
                return (this->_alloc);
            }

            //insert
            ft::pair<iterator,bool>                insert(const value_type& v)
            {
                iterator i = this->find(v.first);
                if (i != this->end())
                    return ft::make_pair(iterator(i), false);
                return (ft::make_pair(iterator(this->_base->insert(v)), true));
            }

            iterator                                insert(iterator position, const value_type& v)
            {
                iterator i = this->find(v.first);
                if (i != this->end())
                    return (position);
                if (position == this->begin() || position == this->end())
                    return (iterator(this->_base->insert(v)));
                return (iterator(this->_base->insert(position.base(), v)));
            }

            template <class InputIterator>
            typename ft::enable_if<ft::is_iterator<InputIterator>::value, void>::type
            insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    this->insert(*first++);
                }
            }
            
            //key_comp
            key_compare                             key_comp() const
            {
                return (this->_key_compare);
            }

            //max_size
            size_type                               max_size() const
            {
                return std::min<size_type>(
                this->_alloc.max_size(),
                std::numeric_limits<difference_type>::max());
            }

            //size
            size_type                               size() const
            {
                return (this->_base->size());
            }

            //swap
            void                                    swap(map& x)
            {
                tree_type *x_buf = x._base;
                x._base = this->_base;
                this->_base = x_buf;
            }

            //value_comp
            value_compare                           value_comp() const
            {
                return (this->_value_compare);
            }



            /*  TODO OPERATORS 
             *  =========
             */
            map                     operator= (const map& x)
            {
                delete this->_base;
                this->_base = new tree_type(*x._base);
                this->_alloc = x._alloc;
                this->_key_compare = x._key_compare;
                this->_value_compare = x._value_compare;
                return (*this);
            }

            mapped_type&            operator[](const key_type& k)
            {
                iterator it = this->find(k);
                if (it != this->end())
                    return (it->second);
                else {
                    this->insert(ft::make_pair(k, mapped_type()));
                    return (this->find(k)->second);
                }
            }
        
        private:
            tree_type                 *_base;
            allocator_type            _alloc;
            key_compare               _key_compare;
            value_compare             _value_compare;
    };


    template <class Key, class T, class Compare, class Allocator>
    bool
    operator==(const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
    }

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator< (const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
    }

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator!=(const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return !(x == y);
    }

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator> (const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return y < x;
    }

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator>=(const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return !(x < y);
    }

    template <class Key, class T, class Compare, class Allocator>
    bool
    operator<=(const map<Key, T, Compare, Allocator>& x,
            const map<Key, T, Compare, Allocator>& y)
    {
        return !(y < x);
    }

    template <class Key, class T, class Compare, class Allocator>
    void    swap (map<Key, T, Compare, Allocator>& x,
                                        map<Key, T, Compare, Allocator>& y)
    {
        x.swap(y);
    }
} 
/*
template<
class Key,
class T,
class Compare,
class Allocator
> 
bool             operator==(const ft::map<Key, T, Compare, Allocator>& lhs, 
                            const ft::map<Key, T, Compare, Allocator>& rhs )
{
    typename ft::map<Key, T, Compare, Allocator>::iterator it = lhs.begin();
    for (typename ft::map<Key, T, Compare, Allocator>::iterator it2 = rhs.begin(); it2 != rhs.end(); ++it2)
    {
        if (*it != it2)
            return (false);
        ++it;
    }
    return (true);
}*/


 /*
            friend bool             operator!=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs )
            {

            }     

            friend bool             operator< ( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs )
            {

            }     

            friend bool             operator<=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs )
            {

            }     

            friend bool             operator> ( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs )
            {

            }     

            friend bool             operator>=( const map<Key, T, Compare, Allocator>& lhs,
                                                const map<Key, T, Compare, Allocator>& rhs )
            {

            }    */ 

#endif // MAP_HPP

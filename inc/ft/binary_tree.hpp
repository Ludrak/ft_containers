
#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

#include <iostream>
#include "reverse_iterator.hpp"


/********************************************************************************/
/*****************************    _tree_node    *********************************/
/********************************************************************************/

template<class T, class Allocator>
struct _tree_node
{
    public:
        typedef Allocator   allocator_type;

    private:
        T               *_value;
        _tree_node      *_left;
        _tree_node      *_right;
        _tree_node      *_parent;
        allocator_type  _alloc;

    public:
        _tree_node()
        : _value(NULL), _left(NULL), _right(NULL), _parent(NULL)
        { }

        _tree_node(const T& value)
        : _left(NULL), _right(NULL), _parent(NULL)
        {
            this->_value = this->_alloc.allocate(1);
            this->_alloc.construct(this->_value, value);
        }

        _tree_node(const _tree_node& tree)
        : _left(tree._left), _right(tree._right), _parent(tree._parent)
        { 
            this->_value = this->_alloc.allocate(1);;
            this->_alloc.construct(this->_value, tree());
        }

        ~_tree_node()
        {
            if (this->_value)
            {
                this->_alloc.deallocate(this->_value, 1);
                this->_alloc.destroy(this->_value);
            }
        }

        T   &operator()() const
        { return (*this->_value); }

        _tree_node* left(void) const
        { return (this->_left); }

        _tree_node* right(void) const
        { return (this->_right); }

        _tree_node* parent(void) const
        { return (this->_parent); }


        void        set_value(const T& v)
        { delete this->_value; this->_value = new T(v); }

        void        set_left(_tree_node *left)
        { this->_left = left; }
        
        void        set_right(_tree_node *right)
        { this->_right = right; }

        void        set_parent(_tree_node *parent)
        { this->_parent = parent; }

        void        swap_value(_tree_node *x)
        {
            T   *v = x->_value;
            x->_value = this->_value;
            this->_value = v;
        }
};

template<class T, class Allocator> bool operator==(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() == b()); }

template<class T, class Allocator> bool operator!=(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() != b()); }

template<class T, class Allocator> bool operator<(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() < b()); }

template<class T, class Allocator> bool operator>(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() > b()); }

template<class T, class Allocator> bool operator<=(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() <= b()); }

template<class T, class Allocator> bool operator>=(const _tree_node<T, Allocator> &a, const _tree_node<T, Allocator> &b)
{ return (a() >= b()); }


/*********************************************************************************/
/*****************************    binary_tree    *********************************/
/*********************************************************************************/

template<class T, class Allocator>
class binary_tree
{
    public:
        typedef _tree_node<T, Allocator>    node_type;
        typedef T                           value_type;

    public:
        class iterator
        {
            public:
                typedef ptrdiff_t                           difference_type;
                typedef T                                   value_type;
                typedef value_type*                         pointer;
                typedef value_type&                         reference;
                typedef ft::bidirectional_iterator_tag      iterator_category;

                iterator() : _value(NULL) {}

                iterator(node_type* v) : _value(v) {}

                iterator(const iterator &iterator) : _value(iterator._value) {}

                node_type*                              base() const
                {
                    return (this->_value);
                }

                iterator&                               operator=(const iterator &rhs)
                {
                    if (this != &rhs)
                        this->_value = rhs._value;
                    return *this;
                }

                reference								operator*(void) const
                {
                    if (this->_value)
                        return (*this->_value)();
                    throw std::out_of_range("cannot dereference on null data");
                }

                pointer									operator->(void) const
                {
                    if (this->_value)
                        return (&(*this->_value)());
                    throw std::out_of_range("cannot dereference on null data");
                }

                bool									operator!=(const iterator &rhs) const
                {
                    return (this->_value != rhs._value);
                }
                
                bool									operator==(const iterator &rhs) const
                {
                    return (this->_value == rhs._value);
                }

                iterator&                               operator++(void)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");
                    
                    reference original = (*this->_value)();
                    if (!this->_value->right())
                    { 
                        while (this->_value && (*this->_value)() <= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->right();
                        while (this->_value->left())
                            this->_value = this->_value->left();
                    }
                    return *this;
                }

                iterator							    operator++(int)
                {
                    iterator copy(*this);
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");
                    
                    reference original = (*this->_value)();
                    if (!this->_value->right())
                    { 
                        while (this->_value && (*this->_value)() <= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->right();
                        while (this->_value->left())
                            this->_value = this->_value->left();
                    }
                    return copy;
                }

                iterator&                               operator--(void)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");

                    reference original = (*this->_value)();
                    if (!this->_value->left())
                    { 
                        while (this->_value && (*this->_value)() >= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->left();
                        while (this->_value->right())
                            this->_value = this->_value->right();
                    }
                    return *this;
                }

                iterator							    operator--(int)
                {
                    iterator copy(*this);
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");
                    
                    reference original = (*this->_value)();
                    if (!this->_value->left())
                    { 
                        while (this->_value && (*this->_value)() >= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->left();
                        while (this->_value->right())
                            this->_value = this->_value->right();
                    }
                    return copy;
                }

            private:
                node_type*     _value;
        };

        class const_iterator
        {
            public:
                typedef ptrdiff_t                           difference_type;
                typedef T                                   value_type;
                typedef value_type*                         pointer;
                typedef value_type&                         reference;
                typedef ft::bidirectional_iterator_tag      iterator_category;

                const_iterator() : _value(NULL) {}

                const_iterator(node_type* v) : _value(v) {}

                const_iterator(const const_iterator &iterator) : _value(iterator._value) {}

                node_type*                              base() const
                {
                    return (this->_value);
                }

                const_iterator&                         operator=(const const_iterator &rhs)
                {
                    if (this != &rhs)
                        this->_value = rhs._value;
                    return *this;
                }

                reference								operator*(void) const
                {
                    if (this->_value)
                        return (*this->_value)();
                    throw std::out_of_range("cannot dereference on null data");
                }

                pointer									operator->(void) const
                {
                    if (this->_value)
                        return (&(*this->_value)());                 
                    throw std::out_of_range("cannot dereference on null data");
                }

                bool									operator!=(const const_iterator &rhs) const
                {
                    return (this->_value != rhs._value);
                }
                
                bool									operator==(const const_iterator &rhs) const
                {
                    return (this->_value == rhs._value);
                }

                const_iterator&                               operator++(void)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");
                    
                    reference original = (*this->_value)();
                    if (!this->_value->right())
                    { 
                        while (this->_value && (*this->_value)() <= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->right();
                        while (this->_value->left())
                            this->_value = this->_value->left();
                    }
                    return *this;
                }

                const_iterator							    operator++(int)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");

                    const_iterator copy(*this);
                      
                    reference original = (*this->_value)();
                    if (!this->_value->right())
                    { 
                        while (this->_value && (*this->_value)() <= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->right();
                        while (this->_value->left())
                            this->_value = this->_value->left();
                    }
                    return copy;
                }

                const_iterator&                               operator--(void)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");

                    reference original = (*this->_value)();
                    if (!this->_value->left())
                    { 
                        while (this->_value && (*this->_value)() >= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->left();
                        while (this->_value->right())
                            this->_value = this->_value->right();
                    }
                    return *this;
                }

                const_iterator							    operator--(int)
                {
                    if (!this->_value)
                        throw std::out_of_range("iterator is out of range");
                 
                    const_iterator copy(*this);

                    reference original = (*this->_value)();
                    if (!this->_value->left())
                    { 
                        while (this->_value && (*this->_value)() >= original) 
                            this->_value = this->_value->parent();
                    }
                    else
                    {
                        this->_value = this->_value->left();
                        while (this->_value->right())
                            this->_value = this->_value->right();
                    }
                    return copy;
                }

            private:
                node_type*     _value;
        };

        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    public:
        binary_tree()
        : _nodes(NULL), _size(0)
        {
            this->_end = new node_type();
            this->_start = this->_end;
        }

        binary_tree(const binary_tree& x)
        : _end(x._end), _start(x._start), _size(x._size)
        {
            if (x._start != x._end)
            {
                this->_nodes = new node_type(*x._nodes);
                _copy_tree(this->_nodes, x._nodes);
                node_type *new_end = new node_type();
                node_type *new_start = new node_type();
                this->highest_bound()->set_right(new_end);
                this->_end = new_end;
                this->lowest_bound()->set_left(new_start);
                this->_start = new_start;
            }
            else
                binary_tree();
        }

        ~binary_tree()
        {
            if (this->_nodes)
                _delete_tree(this->_nodes);
            if (this->_end)
            {
                delete this->_end;
                this->_end = NULL;
            }
        }


        iterator                begin()
        {
            if (!this->_nodes)
                return (iterator(this->_end));
            return (iterator(lowest_bound()));
        }

        const_iterator          begin() const
        {
            if (!this->_nodes)
                return (const_iterator(this->_end));
            return (const_iterator(lowest_bound()));
        }

        iterator                end()
        {
            return (iterator(this->_end));
        }

        const_iterator          end() const
        {
            return (const_iterator(this->_end));
        }

        reverse_iterator        rbegin()
        {
            if (!this->_nodes)
                return (reverse_iterator(this->_start));
            return (reverse_iterator(highest_bound()));
        }

        const_reverse_iterator  rbegin() const
        {
            if (!this->_nodes)
                return (const_reverse_iterator(this->_start));
            return (const_reverse_iterator(highest_bound()));
        }

        reverse_iterator        rend()
        {
            return (reverse_iterator(this->_start));
        }

        const_reverse_iterator  rend() const
        {
            return (const_reverse_iterator(this->_start));
        }

        node_type               *start() const
        {
            return (this->_start);
        }


        /* Note: inserting in this binary tree is insecure if v is already
           contained in the tree, use binary_tree::search before this to 
           avoid unknown behaviour                                         */
        node_type               *insert(const T& v)
        {
            return (insert (this->_nodes, v));
        }

        /* Note: inserting in this binary tree is insecure if v is already
           contained in the tree, use binary_tree::search before this to 
           avoid unknown behaviour                                         */
        node_type    *insert(node_type *buf, const T& v)
        {
            while (buf != NULL)
            {
                if (v <= (*buf)())
                {
                    bool e = (buf->left() == this->_start);
                    if (!buf->left() || e)
                    {
                        buf->set_left(new node_type(v));
                        buf->left()->set_parent(buf);
                        if (e)
                        {
                            buf->left()->set_left(this->_start);
                            this->_start->set_parent(buf->right());
                        }
                        this->_size++;
                        return buf->left();
                    }
                    buf = buf->left();
                }
                else
                {
                    bool e = (buf->right() == this->_end);
                    if (!buf->right() || e)
                    {
                        buf->set_right(new node_type(v));
                        buf->right()->set_parent(buf);
                        if (e)
                        {
                            buf->right()->set_right(this->_end);
                            this->_end->set_parent(buf->right());
                        }
                        this->_size++;
                        return buf->right();
                    }
                    buf = buf->right();
                }
            }
            if (buf == NULL) 
            {
                this->_nodes = new node_type(v);
                this->_nodes->set_right(this->_end);
                if (this->_start == this->_end)
                    this->_start = new node_type();
                this->_nodes->set_left(this->_start);
                this->_size++;
            }
            return this->_nodes;
        }


        bool    empty() const
        {
            return (!this->_nodes || this->_start == this->_end);
        }

        size_t  size() const
        {
            return (this->_size);
        }



        void     erase(const T& v)
        {
            node_type   *elem = this->search(v);
            if (!elem || elem == this->_end || elem == this->_start)
                return;

            bool end = (elem->right() == this->_end);
            bool start = (elem->left() == this->_start);

            /* No children case */
            if ((!elem->left() || start) && (!elem->right() || end))
            {
                if (elem == this->_nodes)
                {
                    this->_nodes = NULL;
                    this->_end->set_parent(NULL);
                    delete this->_start;
                    this->_start = this->_end;
                }
                if (elem->parent() && elem->parent()->right() == elem)
                {
                    if (end)
                    {
                        elem->parent()->set_right(this->_end);
                        this->_end->set_parent(elem->parent());
                    }
                    else
                        elem->parent()->set_right(NULL);
                }
                else if (elem->parent())
                {
                    if (start)
                    {
                        elem->parent()->set_left(this->_start);
                        this->_start->set_parent(elem->parent());
                    }
                    else
                        elem->parent()->set_left(NULL);
                }
                this->_size--;
                delete elem;
            }

            /* One child case */
            else if (((!elem->left() || start) && (elem->right() && !end)) || ((elem->left() && !start) && (!elem->right() || end)))
            {
                node_type *child = (elem->left() != NULL && elem->left() != this->_start) ? elem->left() : elem->right();

                if (elem == this->_nodes)
                    this->_nodes = child;
                
                if (end)
                {
                    node_type   *new_end = highest_bound(child);
                    new_end->set_right(this->_end);
                    this->_end->set_parent(new_end);
                }
                else if (start)
                {
                    node_type   *new_start = lowest_bound(child);
                    new_start->set_left(this->_start);
                    this->_start->set_parent(new_start);
                }
                if (elem->parent())
                {
                    if (elem->parent()->right() == elem)
                    {
                        elem->parent()->set_right(child);
                        child->set_parent(elem->parent());
                    }
                    else
                    {
                        elem->parent()->set_left(child);
                        child->set_parent(elem->parent());
                    }
                }
                else
                    child->set_parent(NULL);
                this->_size--;
                delete elem;
            }

            /* Two child case */
            else
            {
                node_type *successor = upper_bound(v);
                T  s_value = T((*successor)());
                this->erase((*successor)());
                elem->set_value(s_value);
            }
        }



        node_type   *search(const value_type& v) const
        {
            node_type   *buf = this->_nodes;

            while (buf)
            {
                if (v < (*buf)())
                {
                    buf = buf->left();
                    if (buf == this->_start)
                        return (this->_start);
                }
                else if (v > (*buf)())
                {
                    buf = buf->right();
                    if (buf == this->_end)
                        return (this->_end);
                }
                else 
                    return (buf);
            }
            return (NULL);
        }

        node_type  *lowest_bound() const
        {
            node_type   *buf = this->_nodes;

            if (!buf)
                return (NULL);
            while (buf->left() && buf->left() != this->_start)
            {
                buf = buf->left();
            }
            return (buf);
        }

        node_type   *highest_bound() const
        {
            node_type   *buf = this->_nodes;

            if (!buf)
                return (NULL);
            while (buf->right() && buf->right() != this->_end)
            {
                buf = buf->right();
            }
            return (buf);
        }


        node_type  *lowest_bound(node_type* buf) const
        {
            if (!buf)
                return (NULL);
            while (buf->left() && buf->left() != this->_start)
            {
                buf = buf->left();
            }
            return (buf);
        }

        node_type   *highest_bound(node_type* buf) const
        {
            if (!buf)
                return (NULL);
            while (buf->right() && buf->right() != this->_end)
            {
                buf = buf->right();
            }
            return (buf);
        }


        node_type   *lower_bound(const T& v)
        {
            node_type   *buf = this->_nodes;

            while (buf)
            {
                if (v < (*buf)() && buf->left() != this->_start)
                {
                    buf = buf->left();
                }
                else if (v > (*buf)())
                {
                    if ((*buf->right())() > v || buf->right() == this->_end)
                    {
                        return (buf);
                    }
                    buf = buf->right();
                }
                if (buf->left() == this->_start || v == (*buf)())
                    return (buf);
            }
            return (buf);
        }

        node_type   *upper_bound(const T& v) const
        {
            node_type   *buf = this->_nodes;

            while (buf)
            {
                if (v < (*buf)()&& buf->left() != this->_start)
                {
                    if (!buf->left() || (*buf->left())() < v)
                    {
                        return (buf);
                    }
                    buf = buf->left();
                }
                else if (v >= (*buf)() && buf->right() != this->_end)
                {
                    buf = buf->right();
                }
            }
            return (buf);
        }

        void            print() { this->_print_tree(this->_nodes); }

        void            destroy()
        {
            this->_delete_tree(this->_nodes);
            this->_nodes = NULL;
            this->_size = 0;
            delete this->_end;
            this->_end = new node_type();
            this->_start = this->_end;
        }

    private:
        void    _copy_tree(node_type *const buf, const node_type *const src)
        {
            if (src && src->left())
            {
                if (src->left() == this->_start)
                {
                    buf->set_left(NULL);
                }
                else
                {
                    buf->set_left(new node_type(*src->left()));
                    buf->left()->set_parent(buf);
                    _copy_tree(buf->left(), src->left());
                }
            }

            if (src && src->right())
            {
                if (src->right() == this->_end)
                {
                    buf->set_right(NULL);
                }
                else
                {
                    buf->set_right(new node_type(*src->right()));
                    buf->right()->set_parent(buf);
                    _copy_tree(buf->right(), src->right());
                }
            }
        }

        void    _delete_tree(node_type* tree)
        {
            if (!tree)
                return ;

            if (tree->left())
            {
                if (tree->left() != this->_start)
                    _delete_tree(tree->left());
                else if  (this->_start != this->_end)
                {
                    delete this->_start;
                    this->_start = NULL;
                }
            }
            if (tree->right())
            {
                if (tree->right() != this->_end)
                    _delete_tree(tree->right());
                else
                {
                    delete this->_end;
                    this->_end = NULL;
                }
            }
            delete(tree);
        }

        void    _print_tree(const node_type *const n, const int off = 0) const
        {
            static const int STEP = 5;

            int i = 0;
            while (i < off)
            {
                if (i == off - STEP)
                    std::cout  << "────·";
                else if (i == off - STEP*2)
                    std::cout  << "    ├";
                else
                    std::cout  << "    │";
                i += STEP;
            }
            if (n)
            {
                if (n == this->_end)
                    std::cout << "\033[38;2;150;100;100mEND\033[0m/" << std::endl;
                else if (n == this->_start)
                    std::cout << "\033[38;2;140;170;105mSTART\033[0m/" << std::endl;
                else
                    std::cout << "\033[1;32m" << (*n)().first << "\033[0m/" << std::endl;
                if (n == this->_start || n == this->_end)
                    return ;
            }
            else
                std::cout << "\033[38;2;100;100;120mNIL\033[0m/" << std::endl;
            if (n)
            {
                _print_tree(n->right(), off + STEP);
                if (n->right() || n->left())
                {
                    i = 0;
                    while (i < off)
                    {
                        std::cout  << std::string(STEP - 1, ' ') << "│";
                        i += STEP;
                    }
                    std::cout << std::endl;
                }
            }
            if (n)
                _print_tree(n->left(), off + STEP);
        }

    
    private:
        node_type   *_nodes;
        node_type   *_end;
        node_type   *_start;
        size_t      _size;
};


#endif // BINARY_TREE

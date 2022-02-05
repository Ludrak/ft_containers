
#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

// REVIEW : remove if print() is no longer used
#include <iostream>
#include "reverse_iterator.hpp"

template<class T>
struct _tree_node
{
    private:
        T           *_value;
        _tree_node  *_left;
        _tree_node  *_right;
        _tree_node  *_parent;

    public:
        _tree_node()
        : _value(NULL), _left(NULL), _right(NULL), _parent(NULL)
        { }

        _tree_node(const T& value)
        : _value(new T(value)), _left(NULL), _right(NULL), _parent(NULL)
        { }

        _tree_node(const _tree_node& tree)
        : _value(new T(tree())), _left(tree._left), _right(tree._right), _parent(tree._parent)
        { }

        ~_tree_node()
        { delete this->_value; }

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

template<class T> bool operator==(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() == b()); }

template<class T> bool operator!=(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() != b()); }

template<class T> bool operator<(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() < b()); }

template<class T> bool operator>(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() > b()); }

template<class T> bool operator<=(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() <= b()); }

template<class T> bool operator>=(const _tree_node<T> &a, const _tree_node<T> &b)
{ return (a() >= b()); }

template<class T>
class binary_tree
{
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

                iterator(_tree_node<value_type>* v) : _value(v) {}

                iterator(const iterator &iterator) : _value(iterator._value) {}

                value_type                              base() const
                {
                    return ((*this->_value)());
                }

                iterator&                               operator=(const iterator &rhs)
                {
                    if (this != &rhs)
                        this->_value = rhs._value;
                    return *this;
                }

                reference								operator*(void) const
                {
                    //if (this->_value)
                        return (*this->_value)();
                   // throw std::out_of_range("cannot dereference on null data");
                }

                pointer									operator->(void) const
                {
                    if (this->_value)
                        return ((*this->_value)());
                    return (NULL);
                }

                bool									operator!=(const iterator &rhs) const
                {
                    //std::cout << this->_value << " != " << rhs._value << " : " << (this->_value != rhs._value) << std::endl;
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
                        while (this->_value && (*this->_value)() <= original) 
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
                _tree_node<value_type>*     _value;
        };

        typedef ft::reverse_iterator<iterator>  reverse_iterator;

        // REVIEW making nodes = _end by default instead of NULL ?    
        binary_tree()
        : _nodes(NULL), _end(new _tree_node<T>()), _start(this->_end)
        {
            _nodes = NULL;
        }

        binary_tree(const binary_tree& x)
        : _nodes(new _tree_node<T>(*x._nodes)), _end(new _tree_node<T>()), _start(new _tree_node<T>())
        {
            _copy_tree(this->_nodes, x._nodes);
            highest_bound()->set_right(this->_end);
            lowest_bound()->set_left(this->_start);
        }

        ~binary_tree()
        {
            _delete_tree(this->_nodes);
        }


        iterator    begin()
        {
            if (!this->_nodes)
                return (iterator(this->_end));
            return (iterator(lowest_bound()));
        }

        iterator    end()
        {
            return (iterator(this->_end));
        }

        reverse_iterator    rbegin()
        {
            if (!this->_nodes)
                return (reverse_iterator(this->_start));
            return (reverse_iterator(highest_bound()));
        }

        reverse_iterator    rend()
        {
            return (reverse_iterator(this->_start));
        }



        void    insert(const T& v)
        {
            _tree_node<T>   *buf = this->search(v);
            if (buf && buf != this->_end && buf != this->_start && this->_nodes)
                return ;

            buf = this->_nodes;
            while (buf != NULL)
            {
                if (v <= (*buf)())
                {
                    bool e = (buf->left() == this->_start);
                    if (!buf->left() || e)
                    {
                        buf->set_left(new _tree_node<T>(v));
                        buf->left()->set_parent(buf);
                        if (e)
                        {
                            buf->left()->set_left(this->_start);
                            this->_start->set_parent(buf->right());
                        }
                        return ;
                    }
                    buf = buf->left();
                }
                else
                {
                    bool e = (buf->right() == this->_end);
                    if (!buf->right() || e)
                    {
                        buf->set_right(new _tree_node<T>(v));
                        buf->right()->set_parent(buf);
                        if (e)
                        {
                            buf->right()->set_right(this->_end);
                            this->_end->set_parent(buf->right());
                        }
                        return ;
                    }
                    buf = buf->right();
                }
            }
            if (buf == NULL) 
            {
                this->_nodes = new _tree_node<T>(v);
                this->_nodes->set_right(this->_end);
                if (this->_start == this->_end)
                    this->_start = new _tree_node<T>();
                this->_nodes->set_left(this->_start);
            }
            return ;
        }



        void     erase(const T& v)
        {
            std::cout << "erase " << v << std::endl;
            _tree_node<T>   *elem = this->search(v);
            if (!elem || elem == this->_end || elem == this->_start)
                return;

            bool            end = (elem->right() == this->_end);
            bool            start = (elem->left() == this->_start);

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
                delete elem;
            }

            /* One child case */
            else if (((!elem->left() || start) && (elem->right() && !end)) || ((elem->left() && !start) && (!elem->right() || end)))
            {
                _tree_node<T> *child = (elem->left() != NULL && elem->left() != this->_start) ? elem->left() : elem->right();

                if (elem == this->_nodes)
                    this->_nodes = child;
                
                if (end)
                {
                    _tree_node<T>   *new_end = highest_bound(child);
                    new_end->set_right(this->_end);
                    this->_end->set_parent(new_end);
                }
                else if (start)
                {
                    _tree_node<T>   *new_start = lowest_bound(child);
                    new_start->set_left(this->_start);
                    this->_start->set_parent(new_start);
                }
                // REVIEW useless ? 
                /*if (elem->right() == child)
                    elem->set_right(NULL);
                else
                    elem->set_left(NULL);*/
                // REVIEW END

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
                delete elem;
            }



            /* Two child case */
            else
            {
                _tree_node<T> *successor = upper_bound(v);
                T  s_value = T((*successor)());
                this->erase((*successor)());
                elem->set_value(s_value);
            }
        }



        _tree_node<T>   *search(const T& v)
        {
            _tree_node<T>   *buf = this->_nodes;

            while (buf)
            {
                if (v < (*buf)())
                {
                    buf = buf->left();
                    if (buf == this->_start)
                        return (buf);
                }
                else if (v > (*buf)())
                {
                    buf = buf->right();
                    if (buf == this->_end)
                        return (buf);
                }
                else 
                    return (buf);
            }
            return (NULL);
        }

        _tree_node<T>  *lowest_bound()
        {
            _tree_node<T>   *buf = this->_nodes;

            if (!buf)
                return (NULL);
            while (buf->left() && buf->left() != this->_start)
            {
                buf = buf->left();
            }
            return (buf);
        }

        _tree_node<T>   *highest_bound()
        {
            _tree_node<T>   *buf = this->_nodes;

            if (!buf)
                return (NULL);
            while (buf->right() && buf->right() != this->_end)
            {
                buf = buf->right();
            }
            return (buf);
        }


        _tree_node<T>  *lowest_bound(_tree_node<T> *buf)
        {
            if (!buf)
                return (NULL);
            while (buf->left() && buf->left() != this->_start)
            {
                buf = buf->left();
            }
            return (buf);
        }

        _tree_node<T>   *highest_bound(_tree_node<T> *buf )
        {
            if (!buf)
                return (NULL);
            while (buf->right() && buf->right() != this->_end)
            {
                buf = buf->right();
            }
            return (buf);
        }


        _tree_node<T>   *lower_bound(T v)
        {
            _tree_node<T>   *buf = this->_nodes;

            while (buf)
            {
                if (v < (*buf)() && buf->left() != this->_start)
                {
                    buf = buf->left();
                }
                else if (v > (*buf)())
                {
                    if ((*buf->right())() < v || buf->right() == this->_end)
                        return (buf);
                    buf = buf->right();
                }
                if (v == (*buf)())
                    return (buf);
            }
            return (buf);
        }

        _tree_node<T>   *upper_bound(T v)
        {
            _tree_node<T>   *buf = this->_nodes;

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

        void           print() { this->_print_tree(this->_nodes); }



    private:
        void    _copy_tree(_tree_node<T>* buf, const _tree_node<T> *src)
        {
            if (src->left())
            {
                buf->set_left(new _tree_node<T>(*src->left()));
                _copy_tree(buf->left(), src->left());
            }

            if (src->right())
            {
                buf->set_right(new _tree_node<T>(*src->right()));
                _copy_tree(buf->right(), src->right());
            }
        }

        void    _delete_tree(_tree_node<T>* tree)
        {
            if (!tree)
            {
                delete this->_end;
                return ; 
            }
            if (tree->left())
            {
                _delete_tree(tree->left());
            }
            if (tree->right())
            {
                _delete_tree(tree->right());
            }
            delete(tree);
        }

        void    _print_tree(_tree_node<T>  *n, int off = 0)
        {
            static const int step = 5;

            int i = 0;
            while (i < off)
            {
                std::cout  << std::string(step - 1, (i == off - step) ? '-' : ' ') << ((i == off - step) ? "|" : "|");
                i += step;
            }

            if (n)
            {
                if (n == this->_end)
                {
                    std::cout << "\033[38;2;150;100;100mEND\033[0m/" << std::endl;
                    return ;
                }
                else if (n == this->_start)
                {
                    std::cout << "\033[38;2;140;170;105mSTART\033[0m/" << std::endl;
                    return ;
                }
                else
                    std::cout << "\033[1;32m" << (*n)() << "\033[0m/" << std::endl;
            }
            else
                std::cout << "\033[38;2;100;100;120mNIL\033[0m/" << std::endl;

            if (n)
            {
                _print_tree(n->right(), off + step);
                if (n->right() || n->left())
                {
                    i = 0;
                    while (i < off)
                    {
                        std::cout  << std::string(step - 1, ' ') << ((i == off - step) ? "|" : "|");
                        i += step;
                    }
                    std::cout << std::endl;
                }
            }
            if (n)
                _print_tree(n->left(), off + step);
        }

    
    private:
        _tree_node<T>   *_nodes;
        _tree_node<T>   *_end;
        _tree_node<T>   *_start;
};


#endif // BINARY_TREE

//++ behavior

// leaf
//  goto parent
//  while (left) goto left


// only R
//  goto right
//  while (left) goto left

// only L
// -> leaf

// both childs
//  goto right
//  while (left) goto left

//summary
//if (!right) 
//  goto parent
//else
//  goto right
//
//while (left) goto left
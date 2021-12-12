#ifndef VECTOR_HPP
# define VECTOR_HPP

// template<class T, typename Allocator = std::allocator<T> >
// class vector;
//
// /*       TYPES
//  *       =====
//  */           
// typedef T                                           value_type;
// typedef Allocator                                   allocator_type;
// typedef typename allocator_type::reference          reference;
// typedef typename allocator_type::const_reference    const_reference;
// typedef typename allocator_type::pointer            pointer;
// typedef typename allocator_type::const_pointer      const_pointer;
// typedef ptrdiff_t                                   difference_type;
// typedef	size_t                                     size_type;
//
//
//
// /*       ITERATORS
//  *       =========
//  */
// class                                               iterator
// class                                               const_iterator
// typedef ft::reverse_iterator<iterator>              reverse_iterator;
// typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
//
//
//
// /*       CONSTRUCTORS / DESTRUCTORS
//  *       ==========================
//  */  
// explicit vector(const allocator_type& alloc = allocator_type());
//
// explicit vector(size_type n, const value_type& val = value_type(),
//                                         const allocator_type& alloc = allocator_type());
//
// template <class InputIterator>
// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
//
// vector(const vector& x);
//
// virtual ~vector(void);
//
//
//
// /*       MEMBER FUNCTIONS
//  *       ================
//  */
//
// iterator                begin();
// const_iterator          begin() const;
//
// iterator                end();
// const_iterator          end() const;
//
// reverse_iterator        rbegin();
// const_reverse_iterator  rbegin() const;
//
// reverse_iterator        rend();
// const_reverse_iterator  rend() const;
//
// reference               back();
// const_reference         back() const;
//
// reference               front();
// const_reference         front() const;
//
// reference               at (size_type n);
// const_reference         at (size_type n) const;
//
// void                    assign (size_type n, const value_type& val);
// template <class InputIterator>
// void                    assign (InputIterator first, InputIterator last);
//
// size_type               capacity() const;
//
// void                    clear();
//
// bool                    empty() const;
//
// iterator                erase(iterator position);
// iterator                erase(iterator first, iterator last);
//
// allocator_type          get_allocator() const;
//
// iterator                insert(iterator position, const value_type& val);
// void                    insert(iterator position, size_type n, const value_type& val);
// template <class InputIterator>
// void                    insert(iterator position, InputIterator first, InputIterator last);
//
// size_type               max_size() const;
//
// void                    pop_back();
//
// void                    push_back(const value_type& val);
//
// void                    reserve(size_type n);
//
// void                    resize(size_type n, value_type val = value_type());
//
// size_type               size() const;
//
// void                    swap(vector& x);
//
//
//
// /*       OPERATORS
//  *       =========
//  */
// vector&                 operator= (const vector& x);
// reference               operator[](size_type n);
// const_reference         operator[](size_type n) const;
//
//
//
// /*       NON MEMBER OPERATORS FRIENDS
// *        ============================
// */
// friend bool             operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
// friend bool             operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
// friend bool             operator< (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
// friend bool             operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
// friend bool             operator> (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
// friend bool             operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs);
//
//
//
// /*       NON MEMBER OVERLOADS FRIENDS
// *        ============================
// */
// friend void             swap (vector<T, Allocator>& x, vector<T, Allocator>& y);
//
//
//
// /*       PRIVATE FIELDS
//  *       ==============
//  */
// value_type*     _data;
// size_type       _capacity;
// size_type       _size;
// allocator_type  _allocator;

# include "reverse_iterator.hpp"
# include "bit_reference.hpp"
# include "algorithm.hpp"
# include <stdexcept>

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
                    typedef ptrdiff_t                           difference_type;
					typedef T                                   value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    typedef ft::random_access_iterator_tag      iterator_category;
                protected:
					value_type 		*_value;
					
				public:
					iterator() : _value(NULL) { }

					iterator(value_type* val) : _value(val) { }
					
                    iterator(const iterator& src) : _value(src._value) { }

					~iterator() {}

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
						return (this->value);
					}
					
					iterator::difference_type			operator+(const iterator & rhs)
					{
						return (this->_value + rhs._value);
					}
					
					iterator::difference_type			operator-(const iterator & rhs)
					{
						return (this->_value - rhs._value);
					}
					
					iterator							operator+(difference_type n)
					{
						return iterator(this->_value + n);
					}
					
					iterator							operator-(difference_type n)
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

					bool								operator!=(const iterator &rhs) const {
						return (this->_value != rhs._value);
					}

					bool								operator==(const iterator &rhs) const {
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
					bool				operator<(const iterator& rhs)
					{
						return (this->_value < rhs._value);
					}
					
					bool				operator>(const iterator& rhs)
					{
						return (this->_value > rhs._value);
					}
					
					bool				operator<=(const iterator& rhs)
					{
						return (this->_value <= rhs._value);
					}
					
					bool				operator>=(const iterator& rhs)
					{
						return (this->_value >= rhs._value);
					}
            };

            class const_iterator
            {
                public:
                    typedef ptrdiff_t                           difference_type;
					typedef T                                   value_type;
					typedef value_type*                         pointer;
					typedef value_type&                         reference;
                    typedef ft::random_access_iterator_tag      iterator_category;

                protected:
					value_type 		*_value;
					
				public:
					const_iterator() : _value(NULL) {}

					const_iterator(value_type* val) : _value(val) { }
					
					const_iterator(const const_iterator& src) : _value(src._value) { }

					~const_iterator() { }

					const_iterator&                         operator=(const const_iterator &rhs)
					{
						if ( this != &rhs)
							this->_value = rhs._value;
					
						return *this;
					}

					reference								operator*(void) const
					{
						return *(this->_value);
					}

					pointer									operator->(void) const
					{
						return (this->value);
					}
					
					const_iterator::difference_type			operator+(const const_iterator & rhs)
					{
						return (this->_value + rhs._value);
					}
					
					const_iterator::difference_type			operator-(const const_iterator & rhs)
					{
						return (this->_value - rhs._value);
					}
					
					const_iterator							operator+(difference_type n)
					{
						return const_iterator(this->_value + n);
					}
					
					const_iterator							operator-(difference_type n)
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

					bool									operator!=(const const_iterator &rhs) const {
						return (this->_value != rhs._value);
					}
					
					bool									operator==(const const_iterator &rhs) const {
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

					bool									operator<(const const_iterator& rhs)
					{
						return (this->_value < rhs._value);
					}
					
					bool									operator>(const const_iterator& rhs)
					{
						return (this->_value > rhs._value);
					}
					
					bool									operator<=(const const_iterator& rhs)
					{
						return (this->_value <= rhs._value);
					}
					
					bool									operator>=(const const_iterator& rhs)
					{
						return (this->_value >= rhs._value);
					}
            };

            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;




            /*  CONSTRUCTORS / DESTRUCTORS
             *  ==========================
             */  

            explicit vector(const allocator_type& alloc = allocator_type())
            : _data(NULL), _capacity(0), _size(0), _allocator(alloc)
            {};
           
            explicit vector(size_type n, const value_type& val = value_type(),
                                                    const allocator_type& alloc = allocator_type())
            : _data(NULL), _capacity(0), _size(0), _allocator(alloc)
            {
                size_type i = 0;
                this->_data = this->_allocator.allocate(n);
                while (i < n)
                {
                    this->_allocator.construct(&this->_data[i], val);
                    ++i;
                }
                this->_size = n;
                this->_capacity = n;
            }
           
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
           
            vector(const vector& x) : _data(x._data), _capacity(x._capacity), _size(x._size), _allocator(x._allocator) { }

            virtual ~vector(void) { this->_allocator.destroy(_data); }





            /*  MEMBER FUNCTIONS
             *  ================
             */

            //begin
            iterator                begin()
            {
                return (vector<T, Allocator>::iterator(this->_data));
            }

            const_iterator          begin() const
            {
                return (vector<T, Allocator>::const_iterator(this->_data));
            }


            //end
            iterator                end()
            {
                return (vector<T, Allocator>::iterator(&this->_data[this->_size]));
            }

            const_iterator          end() const
            {
                return (vector<T, Allocator>::const_iterator(&this->_data[this->_size]));
            }


            //rbegin
            reverse_iterator        rbegin()
            {
                return (vector<T, Allocator>::reverse_iterator(&this->_data[this->_size - 1]));
            } 
            const_reverse_iterator  rbegin() const
            {
                return (vector<T, Allocator>::const_reverse_iterator(&this->_data[this->_size - 1]));
            } 

            //rend
            reverse_iterator        rend()
            {
                return (vector<T, Allocator>::reverse_iterator(&this->_data[this->_size - 1]));
            }

            const_reverse_iterator  rend() const
            {
                return (vector<T, Allocator>::const_reverse_iterator(&this->_data[this->_size - 1]));
            }

            
            //back
            reference               back()
            {
                return (this->_data[this->_size - 1]);
            }

            const_reference         back() const
            {
                return (this->_data[this->_size - 1]);
            }


            //front
            reference               front()
            {
                return (this->_data[0]);
            }

            const_reference         front() const
            {
                return (this->_data[0]);
            }


            //at
            reference               at (size_type n)
            {
                // TODO implement ft::out_of_range
                if (n >= this->_size)
                    throw std::out_of_range("vector::at TODO ERROR STRING");
                return (this->_data[n]);
            }

            const_reference         at (size_type n) const
            {
                // TODO implement ft::out_of_range
                if (n >= this->_size)
                    throw std::out_of_range("vector::at TODO ERROR STRING");
                return (this->_data[n]);
            }


            //assign
            void                    assign (size_type n, const value_type& val)
            {
                size_type i = 0;

                this->reserve(n);
                this->resize(n);
                while (i < n)
                    this->_allocator.construct(&this->_data[i++], val);
            }

            template <class InputIterator>
            void                    assign (
                typename ft::enable_if< ft::is_iterator<InputIterator>::value, InputIterator >::type first,
                typename ft::enable_if< ft::is_iterator<InputIterator>::value, InputIterator >::type last
            )
            {
                vector<T, Allocator>::size_type i = 0;
                vector<T, Allocator>::difference_type size = std::abs(first - last);

                this->resize(size);
                while (first != last)
                {
                    this->_allocator.destroy(&this->_data[i]);
                    this->_allocator.construct(&this->_data[i++], *first++);
                }
            }


            //capacity
            size_type               capacity() const
            {
                return (this->_capacity);
            }

            //clear
            void                    clear()
            {
                // TODO destroy_data
            }

            //empty
            bool                    empty() const
            {
                return (!this->_size);
            }

            //erase
            iterator                erase(iterator position)
            {
                iterator it = this->begin();

                for (; it != this->end() && it != position; ++it)
                    ;
                if (it == this->end())
                    return this->begin();

                typename vector<T, Allocator>::iterator next_iterator = it + 1;
                while (it != this->end() - 1)
                {
                    *it = *(it + 1);
                    ++it;
                }
                --this->_size;
                return next_iterator;
            }

            iterator                erase(iterator first, iterator last)
            {
                iterator it_first = this->begin();
                iterator it_last = this->begin();

                for (; it_first != this->end() && it_first != first; ++it_first)
                    ;
                for (; it_last != this->end() && it_last != last; ++it_last)
                    ;
                if (it_first == this->end() || it_last == this->end())
                    return this->begin();

                while (it_first != this->end() && it_last != this->end())
                {
                    *it_first = *it_last;
                    ++it_first;
                    ++it_last;
                }
                this->_size -= std::abs(last - first);
                return (it_first);
            }


            //get_allocator
            allocator_type          get_allocator() const
            {
                return (this->_allocator);
            }

            //insert
            iterator                insert(iterator position, const value_type& val)
            {
                typename vector<T, Allocator>::iterator	first = position;
                value_type	buf; 
                value_type	next;

                this->reserve(this->_size + 1);
                this->_size++;
                buf = *position;
                next = *position;
                *position = value_type(val);
                ++position;
                while (position != this->end())
                {
                    buf = next;
                    next = *position;
                    *position = buf;
                    ++position;
                }
                return first;
            }

            void                    insert(iterator position, size_type n, const value_type& val)
            {
                size_type	index;
                size_type	size_buf = this->size();

                if (n == 0)
                    return ;
                this->reserve(this->_size + n);
                this->_size += n;
                index = position - this->begin();
                while (--size_buf >= index)
                    this->_data[size_buf + n] = this->_data[size_buf];
                size_buf = index + n ;
                while (--size_buf >= index)
                    this->_data[size_buf] = value_type(val);
                return ;
            }       
            
            template <class InputIterator>
            void                    insert(
                iterator position,
                typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type first,
                typename ft::enable_if<ft::is_iterator<InputIterator>::value>::type last
                )
            {
                // TODO insert w/ inputiterator
                (void)position;
                (void)first;
                (void)last;
            }       

            //max_size
            size_type               max_size() const
            {
                // TODO ft::numeric_limits
                return std::numeric_limits<difference_type>::max();
            }

            //pop_back
            void                    pop_back()
            {
                if (this->_size > 0)
                {
                    --this->_size;
                    this->_allocator.destroy(this->_data + this->_size + 1); // REVIEW
                }
            }

            //push_back
            void                    push_back(const value_type& val)
            {
                if (this->_size == this->_capacity)
                    this->reserve(this->_size + 1);
                
                this->_allocator.construct(&this->_data[this->_size], val);
                ++this->_size;
            }

            //reserve
            void                    reserve(size_type n)
            {
                size_type i = 0;

                if (n <= this->_capacity)
                    return ;

                typename vector<T, Allocator>::size_type old_capacity = this->_capacity;

                if (n > this->max_size())
                    n = this->max_size();
                if (this->_capacity == 0)
                    ++this->_capacity;
                while (this->_capacity < n)
                    this->_capacity *= 2;
                value_type  *buf = this->_allocator.allocate(this->_capacity);
                while (i < this->_size)
                {
                    this->_allocator.construct(&buf[i], this->_data[i]);
                    ++i;
                }
                // TODO destroy data to destroy replaced data
                this->_allocator.deallocate(this->_data, old_capacity);
                this->_data = buf;
            }

            //resize
            void                    resize(size_type n, value_type val = value_type())
            {
                if (n <= this->_size)
                {
                    while (this->_size > n)
                    {
                        --this->_size;
                        this->_allocator.destroy(&this->_data[this->_size]);
                    }
                }
                else
                {
                    this->reserve(n);
                    while (this->_size < n)
                    {
                        this->_allocator.destroy(&this->_data[this->_size]);
                        this->_allocator.construct(&this->_data[this->_size], val);
                        this->_size++;
                    }
                }
                return ;
            }

            //size
            size_type               size() const
            {
                return (this->_size);
            }

            //swap
            void                    swap(vector& x)
            {
                value_type*     data_buf = x._data;
                size_type       capacity_buf = x._capacity;
                size_type       size_buf = x._size;
                x._data = this->_data;
                x._capacity = this->_capacity;
                x._size = this->_size;
                this->_data = data_buf;
                this->_capacity = capacity_buf;
                this->_size = size_buf;
            }




            /*  OPERATORS
             *  =========
             */

            vector&                 operator= (const vector& x)
            {
                this->_data = x._data;
                this->_capacity = x.capacity;
                this->_size = x._size;
            }

            reference               operator[](size_type n)
            {
                return (this->_data[n]);
            } 

            const_reference         operator[](size_type n) const
            {
                return (this->_data[n]);
            } 


            /*  PRIVATE FIELDS
             *  ==============
             */
        private:

            value_type*     _data;
            size_type       _capacity;
        	size_type       _size;
            allocator_type  _allocator;

    };

    /* NON MEMBER OPERATORS FRIENDS
    *  ============================
    */

    template<class T, class Allocator>
    bool             operator==(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (ft::equal<typename vector<T, Allocator>::const_iterator, typename vector<T, Allocator>::const_iterator > (lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class T, class Allocator>
    bool             operator!=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(ft::equal<typename vector<T, Allocator>::const_iterator, typename vector<T, Allocator>::const_iterator > (lhs.begin(), lhs.end(), rhs.begin()));
    }

    template<class T, class Allocator>
    bool             operator< (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template<class T, class Allocator>
    bool             operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template<class T, class Allocator>
    bool             operator> (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
       return (lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    }

    template<class T, class Allocator>
    bool             operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
    {
        return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }


    /* NON MEMBER OVERLOADS FRIENDS
    *  ============================
    */

    //void             swap (vector<T, Allocator>& x, vector<T, Allocator>& y);
}

#endif // VECTOR_HPP

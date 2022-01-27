#include <iostream>

#include "vector.hpp"
#include <vector>

namespace LIB = ft;

#define UNIT_START(name)        std::cout << "\033[0m-> \033[1;32mUnit\033[0m ("name") : " << std::endl; \
                                int errors = 0; \
                                int max_tests = 0; \

#define UNIT_END                if (errors != 0) \
                                    std::cout << "\033[1;31m✗  Unit Failed ! [" << errors << "/" << max_tests << " KO tests]" << std::endl << std::endl; \
                                else \
                                    std::cout << "\033[1;32m✓  Unit Success \033[0m[\033[1;32m" << max_tests << "\033[0m/\033[1;32m" << max_tests << "\033[0m]\033[0m" << std::endl << std::endl;

#define UNIT_TEST(test_name)    max_tests++; std::cout << " . testing " << test_name << std::endl;
#define UNIT_ERROR(error)       errors++; std::cout << "   \033[1;31mERROR\033[0m: " << error << std::endl << std::endl;

class SomeClass
{
    public:
        SomeClass(int x) : _value(x) { }
    
        int     getValue() const { return this->_value; }
        void    setValue(int v) { this->_value = v; }

    private:
        int _value;
};

int main()
{
    std::cout << "* * *    \033[1;32mVECTOR\033[0m   * * *" << std::endl << std::endl;

    {
        UNIT_START("vector member functions")
            UNIT_TEST("vector(1)")
                LIB::vector<int> vector = LIB::vector<int>();
            
            UNIT_TEST("vector(2)")
                const LIB::vector<SomeClass> const_vector = LIB::vector<SomeClass>(50, SomeClass(42));
                    

            UNIT_TEST("vector::at()")
                for (int i = 0; i < 50; ++i)
                {
                    vector.push_back(i);
                    if (vector.at(i) != i)
                    {
                        UNIT_ERROR("vector::at() : output doesn't match: " << vector.at(i) << " (expecting " << i << ")")
                        break;
                    }
                }
            UNIT_TEST("vector::back()")
                int &k = vector.back();
                if (k != 49)
                {
                    UNIT_ERROR("vector::back() : output doesn't match: " << k << " (expecting " << 49 << ")")
                }
            UNIT_TEST("vector::front()")
                int &l = vector.front();
                if (l != 0)
                {
                    UNIT_ERROR("vector::front() : output doesn't match: " << l << " (expecting " << 0 << ")")
                }
            UNIT_TEST("vector::assing(1) ")
                LIB::vector<int> assign_vector = LIB::vector<int>();
                assign_vector.assign((size_t)12, 42);
                if (assign_vector.capacity() != 12)
                {
                    UNIT_ERROR("vector::assign() : capacity doesn't match: " << assign_vector.capacity() << " (expecting " << 12 << ")")
                }
                if (assign_vector.size() != 12)
                {
                    UNIT_ERROR("vector::assign() : size doesn't match: " << assign_vector.size() << " (expecting " << 12 << ")")
                }
                {
                    int i = 0;
                    for (LIB::vector<int>::iterator it = assign_vector.begin(); it != assign_vector.end(); ++it)
                    {
                        if (*it != 42)

                        i++;
                    }
                }

            UNIT_TEST("vector::assing(2) ")
                LIB::vector<int> assign_vector_range = LIB::vector<int>();
                assign_vector_range.assign(assign_vector.begin(), assign_vector.end());
                if (assign_vector_range.capacity() != 12)
                {
                    UNIT_ERROR("vector::assign() : capacity doesn't match: " << assign_vector_range.capacity() << " (expecting " << 12 << ")")
                }
                if (assign_vector_range.size() != 12)
                {
                    UNIT_ERROR("vector::assign() : size doesn't match: " << assign_vector_range.size() << " (expecting " << 12 << ")")
                }
                {
                int i = 0;
                    for (LIB::vector<int>::iterator it = assign_vector_range.begin(); it != assign_vector_range.end(); ++it)
                    {
                        if (*it != 42)

                        i++;
                    }
                }
            
            UNIT_TEST("vector::capacity()")
                if (assign_vector.capacity() != 12)
                {
                    UNIT_ERROR("vector::capacity() : capacity doesn't match: " << assign_vector_range.capacity() << " (expecting " << 12 << ")")
                }
            UNIT_TEST("vector::reserve()")
                assign_vector.reserve(14);
                if (assign_vector.capacity() != 14)
                {
                    UNIT_ERROR("vector::reserve(> capacity) : capacity doesn't match: " << assign_vector_range.capacity() << " (expecting " << 14 << ")")
                }
                assign_vector.reserve(12);
                if (assign_vector.capacity() != 14)
                {
                    UNIT_ERROR("vector::reserve(< capacity) : capacity doesn't match: " << assign_vector_range.capacity() << " (expecting " << 14 << ")")
                }
            
            UNIT_TEST("vector::resize()")
                assign_vector.resize(2);
                if (assign_vector.capacity() != 14)
                {
                    UNIT_ERROR("vector::resize() : capacity doesn't match: " << assign_vector_range.capacity() << " (expecting " << 14 << ")")
                }
                else if (assign_vector.size() != 2)
                {
                    UNIT_ERROR("vector::resize() : size doesn't match: " << assign_vector_range.size() << " (expecting " << 2 << ")")
                }

            UNIT_TEST("vector::clear()")
                assign_vector.clear();
                if (assign_vector.size() != 0)
                {
                    UNIT_ERROR("vector::clear() : size doesn't match: " << assign_vector_range.size() << " (expecting " << 0 << ")")
                }

            UNIT_TEST("vector::empty()")
                if (!assign_vector.empty())
                {
                    UNIT_ERROR("vector::empty() : size doesn't match: " << assign_vector_range.size() << " (expecting " << 0 << ")")
                }
            
            UNIT_TEST("vector::erase(1)")
                LIB::vector<int>    vec = LIB::vector<int>();
                vec.reserve(10);
                for (int i = 0; i < 10; ++i)
                    vec.push_back(i);
                vec.erase(vec.begin() + 2);
                if (vec.at(2) != 3)
                {
                    UNIT_ERROR("vector::erase(1) : value does not match: " << vec.at(2) << " expecting " << 3);
                }

            UNIT_TEST("vector::erase(2)")
                vec.erase(vec.begin() + 2, vec.end() - 2);
                if (vec.size() != 4)
                {
                    UNIT_ERROR("vector::erase(2): size does not match: " << vec.size() << " expecting " << 5);
                }
            
            UNIT_TEST("vector::get_allocator()")
                vec.get_allocator();     

            UNIT_TEST("vector::insert(1)")
                vec.clear();
                vec.insert(vec.begin(), 42);
                if (vec.at(0) != 42)
                {
                    UNIT_ERROR("vector::insert(1): wrong insertion: 42 not at begin() iterator");
                }
            
            UNIT_TEST("vector::insert(2)")
                vec.insert(vec.begin() + 1, (size_t)4, 101);
                if (vec.at(0) != 42)
                {
                    UNIT_ERROR("vector::insert(2): insertion deleted bad value, 42 is no more at start of vec");
                }
                for (int i = 1; i < 5; ++i)
                {
                    if (vec.at(i) != 101)
                    {
                        UNIT_ERROR("vector::insert(2): wrong insertion: 101 not at " << i << " of vector");
                    }
                }
            UNIT_TEST("vector::insert(3)")
                int arr[] = {1, 2, 3, 4};
                vec.insert(vec.begin() + 1, arr, arr + 4);
                
                if (vec.at(0) != 42)
                {
                    UNIT_ERROR("vector::insert(2): insertion deleted bad value, 42 is no more at start of vec");
                }
                int ic = 0;
                for (int i = 1; i < 5; ++i)
                {
                    ic++;
                    if (vec.at(i) != ic)
                    {
                        UNIT_ERROR("vector::insert(2): wrong insertion " << vec.at(i) << " expecting " << ic);
                    }
                }
                for (int i = 5; i < 9; ++i)
                {
                    if (vec.at(i) != 101)
                    {
                        UNIT_ERROR("vector::insert(2): insertion deleted bad value, 101 is no more at " << i << " of vector");
                    }
                }
            UNIT_TEST("vector::max_size()")
                std::vector<int> stdref;
                if (stdref.max_size() != vec.max_size())
                {
                    UNIT_ERROR("vector::max_size(): value does not match: " << vec.max_size() << " expecting " << stdref.max_size());
                }
            
            UNIT_TEST("vector::pop_back()")
                vec.clear();
                vec.push_back(0);
                vec.push_back(1);
                vec.push_back(2);
                vec.push_back(3);
                vec.pop_back();
                if (*(vec.end() - 1) == 3)
                {
                    UNIT_ERROR("vector::pop_back(): operation did not pop the last element")
                }

            UNIT_TEST("vector::push_back()")
                vec.clear();
                size_t new_capacity =  vec.capacity();

                for (int i = 0; i < 50; ++i)
                {
                    vec.push_back(i);
                    if (new_capacity != vec.capacity())
                    {
                        if (new_capacity * 2 != vec.capacity() && (new_capacity != 0 && vec.capacity() != 1))
                        {
                            UNIT_ERROR("vector::push_back() : capacity doesn't increase by *2 factor (" << new_capacity * 2 << " expecting " << vec.capacity() << ")")
                        }
                        new_capacity = vec.capacity();
                    }
                }
            
            UNIT_TEST("vector::reserve()")
                vec.reserve(10);
                if (vec.capacity() != 80)
                {
                    UNIT_ERROR("vector::reserve() : capacity doesn't match: " << vec.capacity() << " expecting " << 10);
                }

                vec.reserve(5);
                if (vec.capacity() != 80)
                {
                    UNIT_ERROR("vector::reserve() : capacity doesn't match: " << vec.capacity() << " expecting " << 10);
                }

            UNIT_TEST("vector::resize()")
                vec.resize(2);
                if (vec.size() != 2)
                {
                    UNIT_ERROR("vector::resize(): shrink failed, size does not correspond: " << vec.size() << " expecting " << 2);
                }
                vec.resize(4);
                if (vec.size() != 4)
                {
                    UNIT_ERROR("vector::resize(): expand failed, size does not correspond: " << vec.size() << " expecting " << 2);
                }
                vec.resize(6, 42);
                if (vec.size() != 6)
                {
                    UNIT_ERROR("vector::resize(): expand (with replace var) failed, size does not correspond: " << vec.size() << " expecting " << 2);
                }
                if (*(vec.end() - 2) != 42 || *(vec.end() - 1) != 42)
                {
                    UNIT_ERROR("vector::resize(): expand (with replace var) failed, expanded value does not correspond");
                }
            
            UNIT_TEST("vector::size()")
                if (vec.size() != 6)
                {
                    UNIT_ERROR("vector::size(): value does not correspond: " << vec.size() << " expecting " << 0);
                }

            UNIT_TEST("vector::swap()")
                LIB::vector<int> vec2 = LIB::vector<int>();
                vec2.push_back(2);
                vec2.push_back(2);
                vec2.push_back(2);
                vec2.push_back(2);

                vec.clear();
                vec.push_back(1);
                vec.push_back(1);
                vec.push_back(1);
                vec.push_back(1);

                vec.swap(vec2);

                if (*vec.begin() == 1)
                {
                    UNIT_ERROR("vector::swap(): value does not correspond: " << *vec.begin() << " expecting " << 2);
                }

                if (*vec2.begin() == 2)
                {
                    UNIT_ERROR("vector::swap(): value does not correspond: " << *vec2.begin() << " expecting " << 1);
                }

        UNIT_END
    }



    /*******************************************************************************/
    /********************************** ITERATORS **********************************/
    /*******************************************************************************/

    {
        UNIT_START("vector iterators")
            LIB::vector<int> vector = LIB::vector<int>();
            for (int i = 0; i < 50; ++i)
                    vector.push_back(i);
            const LIB::vector<SomeClass> const_vector = LIB::vector<SomeClass>(50, SomeClass(42));

            UNIT_TEST("vector::iterator() [0...50]")
                int i = 0;
                for (LIB::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
                {
                    if (*it != i++)
                    {
                        UNIT_ERROR("vector::iterator::operator*') : output doesn't match: " << *it << " (expecting " << i << ")")
                        break;
                    }
                    else if (!(it == it))
                    {
                        UNIT_ERROR("vector::const_iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("vector::const_iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (it < it - 1)
                    {
                        UNIT_ERROR("vector::const_iterator::operator<() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (it > it + 1)
                    {
                        UNIT_ERROR("vector::const_iterator::operator>() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (!(it <= it))
                    {
                        UNIT_ERROR("vector::const_iterator::operator<=() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (!(it >= it))
                    {
                        UNIT_ERROR("vector::const_iterator::operator>=() : output doesn't match: false (expecting true )")
                        break;
                    }
                }
            
            UNIT_TEST("vector::reverse_iterator() [50...0]")
                for (LIB::vector<int>::reverse_iterator it = vector.rbegin(); it != vector.rend(); ++it)
                {
                    //std::cout << i - 1 << std::endl;
                    if (*it != --i) 
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator* : output doesn't match: " << *it << " (expecting " << i << ")")
                        break;
                    }
                    else if (!(it == it))
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (it < it - 1)
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator<() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (it > it + 1)
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator>() : output doesn't match: true (expecting false)")
                        break;
                    }
                    else if (!(it <= it))
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator<=() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (!(it >= it))
                    {
                        UNIT_ERROR("vector::reverse_iterator::operator>=() : output doesn't match: false (expecting true )")
                        break;
                    }
                }
            
            UNIT_TEST("vector::const_iterator() [0...50]")
                for (LIB::vector<SomeClass>::const_iterator it = const_vector.begin(); it != const_vector.end(); ++it)
                {
                    if (it->getValue() != 42)
                    {
                        UNIT_ERROR("vector::const_iterator::operator->() : output doesn't match: " << it->getValue() << " (expecting " << 42 << ")")
                        break;
                    }
                }

            UNIT_TEST("vector::const_reverse_iterator() [50...0]")
                for (LIB::vector<SomeClass>::const_reverse_iterator it = const_vector.rbegin(); it != const_vector.rend(); ++it)
                {
                    if (it->getValue() != 42)
                    {
                        UNIT_ERROR("vector::const_iterator::operator->() : output doesn't match: " << it->getValue() << " (expecting " << 42 << ")")
                        break;
                    }
                }
        UNIT_END
    }

    /*******************************************************************************/
    /********************************** OPERATORS **********************************/
    /*******************************************************************************/
    {
        UNIT_START("vector operators")
            UNIT_TEST("vector::operator=")
                LIB::vector<int> vec = LIB::vector<int>();
                LIB::vector<int> vec2 = LIB::vector<int>();
                vec2.push_back(1);
                vec2.push_back(2);
                vec2.push_back(3);
                vec = vec2;
                if (vec.at(0) != 1 || vec.at(1) != 2 || vec.at(2) != 3)
                {
                    UNIT_ERROR("vector::operator= : no/partial copy of vector");
                }

            UNIT_TEST("vector::operator[]")
                if (vec[0] != 1 || vec[2] != 3)
                {
                    UNIT_ERROR("vector::operator[] : value does not match");
                }

            UNIT_TEST("vector::operator==")
                if (!(vec == vec2))
                {
                    UNIT_ERROR("operator== : equals vectors are not equals");
                }

            UNIT_TEST("vector::operator!=")
                if (vec != vec2)
                {
                    UNIT_ERROR("operator!= : equals vectors are different");
                }

            UNIT_TEST("vector::operator<=")
                if (!(vec <= vec2))
                {
                    UNIT_ERROR("operator<= : equals vectors are not equals");
                }
                vec2.resize(2);
                if (vec <= vec2)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }


            UNIT_TEST("vector::operator<")
                if (vec < vec2)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }

            UNIT_TEST("vector::operator>=")
                vec2.resize(3, 3);
                if (!(vec >= vec2))
                {
                    UNIT_ERROR("operator<= : equals vectors are not equals");
                }
                vec2.resize(2);
                if (vec2 >= vec)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }

            UNIT_TEST("vector::operator>")
                if (vec2 >= vec)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }
        UNIT_END
    }

    {
        UNIT_START("vector non member functions")
            UNIT_TEST("vector::swap()")
            LIB::vector<int> vec = LIB::vector<int>();
            vec.push_back(1);
            vec.push_back(1);
            vec.push_back(1);
            vec.push_back(1);
            LIB::vector<int> vec2 = LIB::vector<int>();
            vec2.push_back(2);
            vec2.push_back(2);
            vec2.push_back(2);
            vec2.push_back(2);


            LIB::swap(vec, vec2);

            if (*vec.begin() == 1)
            {
                UNIT_ERROR("vector::swap(): value does not correspond: " << *vec.begin() << " expecting " << 2);
            }

            if (*vec2.begin() == 2)
            {
                UNIT_ERROR("vector::swap(): value does not correspond: " << *vec2.begin() << " expecting " << 1);
            }
        UNIT_END
    }
    return (0);
}
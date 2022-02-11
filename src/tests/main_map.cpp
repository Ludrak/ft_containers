#include <iostream>

#include "map.hpp"
#include <map>

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

int main()
{
    std::cout << "* * *    \033[1;32mMAP\033[0m   * * *" << std::endl << std::endl;

    {
        UNIT_START("map member functions")
            UNIT_TEST("map::map(1)")
                LIB::map<int, std::string> map1 = LIB::map<int, std::string>();
                map1.insert(LIB::make_pair(3, "hello03"));
                map1.insert(LIB::make_pair(5, "hello05"));
                map1.insert(LIB::make_pair(4, "hello04"));
                map1.insert(LIB::make_pair(2, "hello02"));
                map1.insert(LIB::make_pair(1, "hello01"));
            
            UNIT_TEST("map::map(2)")
                LIB::map<int, std::string> map2 = LIB::map<int, std::string>(map1.begin(), map1.end());
                int i = 1;
                for (LIB::map<int, std::string>::iterator it = map2.begin(); it != map2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("insertion constructor: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
        
            UNIT_TEST("map::map(3)")
                LIB::map<int, std::string> map3 = LIB::map<int, std::string>(map2);
                i = 1;
                for (LIB::map<int, std::string>::iterator it = map2.begin(); it != map2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("copy constructor: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
            UNIT_TEST("map::begin()")
                if (map1.begin()->first != 1)
                {
                    UNIT_ERROR("begin: value does not match: " << map1.begin()->first << " expecting " << 1);
                }

            UNIT_TEST("map::clear()")
                map3.clear();
                if (map3.begin() != map3.end())
                {
                    UNIT_ERROR("clear: uncleared iterators");
                }
                if (map3.size() != 0)
                {
                    UNIT_ERROR("clear: map size doesn't match : " << map3.size() << " expecting 0");
                }
            UNIT_TEST("map::count()")
                if (!map1.count(1))
                {
                    UNIT_ERROR("count: element in map wasn't counted 1")
                }
                if (!map1.count(2))
                {
                    UNIT_ERROR("count: element in map wasn't counted 2")
                }
                if (!map1.count(3))
                {
                    UNIT_ERROR("count: element in map wasn't counted 3")
                }
                if (!map1.count(4))
                {
                    UNIT_ERROR("count: element in map wasn't counted 4")
                }
                if (!map1.count(5))
                {
                    UNIT_ERROR("count: element in map wasn't counted 5")
                }
                
                if (map1.count(42))
                {
                    UNIT_ERROR("count: element not in map was counted")
                }
            UNIT_TEST("map::empty()")
                if (!map3.empty())
                {
                    UNIT_ERROR("map: empty failed");
                }
            UNIT_TEST("map::end()")
                map1.end();
            UNIT_TEST("map::equal_range()")
                if (map1.equal_range(3).first->first != 3)
                {
                    UNIT_ERROR("first does not match: " << map1.equal_range(3).first->first << " expecting 3");
                }
                else if (map1.equal_range(3).second->first != 4)
                {
                    UNIT_ERROR("second does not match: " << map1.equal_range(3).second->first << " expecting 4");
                }
            UNIT_TEST("map::erase(1)")
                map1.erase(5);
                if (map1.rbegin()->first == 5)
                {
                    UNIT_ERROR("no deletion on single element");
                }
            UNIT_TEST("map::erase(2)")
                map1.erase(map1.begin());
                if (map1.begin()->first == 1)
                {
                    UNIT_ERROR("no deletion on position iterator element");
                }
            UNIT_TEST("map::erase(3)")
                map1.erase(map1.begin(), map1.end());
                if (!map1.empty())
                {
                    UNIT_ERROR("no deletion on iterator erase");
                }
            UNIT_TEST("map::find()")
                if (map2.find(4) == map2.end())
                {
                    UNIT_ERROR("not found in map element");
                }
                if (map2.find(42) != map2.end())
                {
                    UNIT_ERROR("found not in map element");
                }
            UNIT_TEST("map::get_allocator()")
                map2.get_allocator(); // just to see if defined
            UNIT_TEST("map::insert(1)")
                LIB::map<int, std::string> m = LIB::map<int, std::string>();
                m.insert(LIB::make_pair(3, "hello03"));
                m.insert(LIB::make_pair(5, "hello05"));
                m.insert(LIB::make_pair(4, "hello04"));
                m.insert(LIB::make_pair(2, "hello02"));
                m.insert(LIB::make_pair(1, "hello01"));
                i = 1;
                for (LIB::map<int, std::string>::iterator it = map2.begin(); it != map2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("insert: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
            UNIT_TEST("map::insert(2)")
                m.clear();
                m.insert(m.begin(), LIB::make_pair(3, "hello03"));
                m.insert(m.begin(), LIB::make_pair(5, "hello05"));
                m.insert(m.begin(), LIB::make_pair(4, "hello04"));
                m.insert(m.begin(), LIB::make_pair(2, "hello02"));
                m.insert(m.begin(), LIB::make_pair(1, "hello01"));                i = 1;
                for (LIB::map<int, std::string>::iterator it = map2.begin(); it != map2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("insert: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
            UNIT_TEST("map::insert(3)")
                m.clear();
                m.insert(map2.begin(), map2.end());
                i = 1;
                for (LIB::map<int, std::string>::iterator it = map2.begin(); it != map2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("insert: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
            UNIT_TEST("map::key_comp()")
                {
                    LIB::less<int> comp_test = m.key_comp();
                    (void)comp_test;
                }
            UNIT_TEST("map::lower_bound()")
                if (m.lower_bound(3)->first != 3)
                {
                    UNIT_ERROR("lower_bound: value does not match: " << m.lower_bound(3)->first << " expecting 3");
                }
                if (m.lower_bound(0) != m.begin())
                {
                    UNIT_ERROR("lower_bound: value does not match: ? expecting begin");
                }
            UNIT_TEST("map::max_size()")
                m.max_size(); // just to see if defined (on map max_size depends on implemented node_type)
            UNIT_TEST("map::operator=")
                LIB::map<int, std::string> m2 = m;
                i = 1;
                for (LIB::map<int, std::string>::iterator it = m2.begin(); it != m2.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("operator=: first doesn't match: " << it->first << " expecting " << i);
                    }
                }
            UNIT_TEST("map::operator[]")
                if (m[3] != "hello03")
                {
                    UNIT_ERROR("operator[]: value does not match: " << m[3] << " expecting " << "hello03" )
                }

                if (m[12] != "" || m.find(12) == m.end())
                {
                    UNIT_ERROR("operator[]: value not inserted")
                }
            UNIT_TEST("map::rbegin()")
                m.rbegin();
            UNIT_TEST("map::rend()")
                m.rend();
            UNIT_TEST("map::size()")
                if (m.size() != 6)
                {
                    UNIT_ERROR("size: value does not match");
                }
           UNIT_TEST("map::swap()")
                LIB::map<int, std::string> map_swapped = LIB::map<int, std::string>();
                m.swap(map_swapped);
                if (!m.empty())
                {
                    UNIT_ERROR("swap: swapper wasn't swapped");
                }
                if (map_swapped.size() != 6)
                {
                    UNIT_ERROR("swap: swapped wasn't swapped (size: " << map_swapped.size() << ")");
                }
            UNIT_TEST("map::upper_bound()")
                if (map_swapped.upper_bound(3)->first != 4)
                {
                    UNIT_ERROR("upper_bound: value does not match: " << m.upper_bound(3)->first << " expecting 4");
                }
                if (map_swapped.upper_bound(5)->first != 12)
                {
                    UNIT_ERROR("upper_bound: value does not match: ? expecting end");
                }
            UNIT_TEST("map::value_comp()")
                m.value_comp();

        UNIT_END
    }



    {
        UNIT_START("map iterators")
        LIB::map<int, std::string> map = LIB::map<int, std::string>();
        for (int i = 0; i < 50; ++i)
                map.insert(LIB::make_pair(i, "hello"+std::to_string(i)));
        const LIB::map<int, std::string> const_map = LIB::map<int, std::string>(map);

            UNIT_TEST("map::iterator()")
            {
                int i = 0;
                for (LIB::map<int, std::string>::iterator it = map.begin(); it != map.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("map::iterator::operator*() : output doesn't match: " << it->first << " (expecting " << i << ")")
                        break;
                    }
                else if (!(it == it))
                    {
                        UNIT_ERROR("map::iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("map::iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                }
                i = 0;
                for (LIB::map<int, std::string>::iterator it = map.begin(); it != map.end(); it++)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("map::iterator::operator*() : output doesn't match: " << it->first << " (expecting " << i << ")")
                        break;
                    }
                else if (!(it == it))
                    {
                        UNIT_ERROR("map::iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("map::iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                }
            }
            /*
            UNIT_TEST("map::const_iterator()")
            {
                int i = 0;
                for (LIB::map<int, std::string>::const_iterator it = const_map.begin(); it != const_map.end(); ++it)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("map::const_iterator::operator*() : output doesn't match: " << it->first << " (expecting " << i << ")")
                        break;
                    }
                else if (!(it == it))
                    {
                        UNIT_ERROR("map::const_iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("map::const_iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                }
                i = 0;
                for (LIB::map<int, std::string>::const_iterator it = const_map.begin(); it != const_map.end(); it++)
                {
                    if (it->first != i++)
                    {
                        UNIT_ERROR("map::const_iterator::operator*() : output doesn't match: " << it->first << " (expecting " << i << ")")
                        break;
                    }
                else if (!(it == it))
                    {
                        UNIT_ERROR("map::const_iterator::operator==() : output doesn't match: false (expecting true )")
                        break;
                    }
                    else if (it != it)
                    {
                        UNIT_ERROR("map::const_iterator::operator!=() : output doesn't match: true (expecting false)")
                        break;
                    }
                }
            }*/
            
        UNIT_END
    }
    return (0);
}
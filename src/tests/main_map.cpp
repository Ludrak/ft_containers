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
                    UNIT_ERROR("lower_bound: value does not match: ? expecting end");
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
            UNIT_TEST("map::rend()")
            UNIT_TEST("map::size()")
            UNIT_TEST("map::swap()")
            UNIT_TEST("map::upper_bound()")
            UNIT_TEST("map::value_comp()")


        UNIT_END
    }
    /*
    LIB::map<int, std::string>  m = LIB::map<int, std::string>();

    m.insert(LIB::make_pair(1, std::string("hello00")));
    m.insert(LIB::make_pair(7, std::string("hello01")));
    m.insert(LIB::make_pair(3, std::string("hello02")));
    m.insert(LIB::make_pair(10, std::string("hello03")));
    m.insert(LIB::make_pair(8, std::string("hello04")));
    m.insert(LIB::make_pair(2, std::string("hello05")));
    m.insert(LIB::make_pair(5, std::string("hello06")));
    m.insert(LIB::make_pair(9, std::string("hello07")));
    m.insert(LIB::make_pair(4, std::string("hello08")));
    m.insert(LIB::make_pair(6, std::string("hello09")));

    ft::pair<LIB::map<int, std::string>::iterator, bool> p = m.insert(LIB::make_pair(6, std::string("hello09")));
    std::cout << "double insert (should be 0) : " << p.second << std::endl;

    for (LIB::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
    {
        std::cout << "++iterator: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << "iterator++: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it)
    {
        std::cout << "++reverse_iterator: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
    {
        std::cout << "reverse_iterator++: " << it->first << " = " << it->second << std::endl;
    }
    


    
    const LIB::map<int, std::string> map2 = LIB::map<int, std::string>(m);

    for (LIB::map<int, std::string>::const_iterator it = map2.begin(); it != map2.end(); ++it)
    {
        std::cout << "++const_iterator: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::const_iterator it = map2.begin(); it != map2.end(); it++)
    {
        std::cout << "const_iterator++: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::const_reverse_iterator it = map2.rbegin(); it != map2.rend(); ++it)
    {
        std::cout << "++const_reverse_iterator: " << it->first << " = " << it->second << std::endl;
    }
    for (LIB::map<int, std::string>::const_reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
    {
        std::cout << "const_reverse_iterator++: " << it->first << " = " << it->second << std::endl;
    }

    LIB::map<int, std::string>  map_insert2 = LIB::map<int, std::string>();

    map_insert2.insert(map_insert2.begin(), LIB::make_pair(1, std::string("hello00")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(7, std::string("hello01")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(3, std::string("hello02")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(10, std::string("hello03")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(8, std::string("hello04")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(2, std::string("hello05")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(5, std::string("hello06")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(9, std::string("hello07")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(4, std::string("hello08")));
    map_insert2.insert(map_insert2.begin(), LIB::make_pair(6, std::string("hello09")));
    for (LIB::map<int, std::string>::iterator it = map_insert2.begin(); it != map_insert2.end(); ++it)
    {
        std::cout << "insert(2): " << it->first << " = " << it->second << std::endl;
    }

    LIB::map<int, std::string>  map_insert3 = LIB::map<int, std::string>();
    map_insert3.insert(map_insert2.begin(), map_insert2.end());
    for (LIB::map<int, std::string>::iterator it = map_insert3.begin(); it != map_insert3.end(); ++it)
    {
        std::cout << "insert(3): " << it->first << " = " << it->second << std::endl;
    }*/
    return (0);
}
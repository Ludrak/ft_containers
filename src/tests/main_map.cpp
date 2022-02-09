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
    std::cout << "* * *    \033[1;32mVECTOR\033[0m   * * *" << std::endl << std::endl;

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
           // UNIT_TEST("map::")
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
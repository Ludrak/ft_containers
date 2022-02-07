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
    return (0);
}
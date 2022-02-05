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

class SomeClass
{
    public:
        SomeClass(int x) : _value(x) { }
    
        int     getValue() const { return this->_value; }
        void    setValue(int v) { this->_value = v; }

    private:
        int _value;
};

#include <cstdlib>
#include <random>

int main()
{
    std::cout << "* * *    \033[1;32mMAP\033[0m   * * *" << std::endl << std::endl;

    {
      /*  LIB::map<int, std::string>    map = LIB::map<int, std::string>();
        map.insert(LIB::make_pair(1, "hey"));*/

        binary_tree<int> bt = binary_tree<int>();

        bt.insert(3);
        bt.insert(4);
        bt.insert(9);
        bt.insert(1);
        bt.insert(5);
        bt.insert(7);
        bt.insert(10);
        bt.insert(12);
        bt.insert(2);
        bt.insert(6);
        bt.insert(8);
        bt.insert(11);

        std::cout << "printing tree: " << std::endl;
        bt.print();
        
        /*
        bt.erase(12);
        bt.erase(11);
        bt.erase(10);
        bt.erase(5);
        bt.erase(4);
        bt.erase(1);*/
        bt.erase(2);
        bt.erase(3);
        bt.erase(9);
        bt.erase(8);
        bt.erase(7);
        bt.erase(6);
        

        std::cout << "printing tree: " << std::endl;
        bt.print();
        

/*
        std::map<int, int> m = std::map<int, int>();
        m.insert(std::make_pair(3, 0));
        m.insert(std::make_pair(4, 0));
        m.insert(std::make_pair(9, 0));
        m.insert(std::make_pair(1, 0));
        m.insert(std::make_pair(5, 0));
        m.insert(std::make_pair(7, 0));
        m.insert(std::make_pair(10, 0));
        m.insert(std::make_pair(12, 0));
        m.insert(std::make_pair(2, 0));
        m.insert(std::make_pair(6, 0));
        m.insert(std::make_pair(8, 0));
        m.insert(std::make_pair(11, 0));
        int i = 0;
        for (std::map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
        {
            std::cout << "value: " << it->first << std::endl;

            if (i++ > 15)
            {
                std::cout << "..." << std::endl;
                return 0;
            }
        }
*/

        int i = 0;
        for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); ++it)
        {
            std::cout << "value: " << *it << std::endl;

            if (i++ > 15)
            {
                std::cout << "..." << std::endl;
                return 0;
            }
        }
       // std::cout << "elem: " << *bt.get_elem(-9) << std::endl;
       // std::cout << "elem: " << *bt.get_elem(389) << std::endl;
        /*
        {
            UNIT_START("map member functions")
            
            UNIT_END
        }

        {
            UNIT_START("map iterators")
            
            UNIT_END
        }

        {
            UNIT_START("map operators")
        
            UNIT_END
        }

        {
            UNIT_START("map non member functions")
        
            UNIT_END
        }*/
    }
    return (0);
}

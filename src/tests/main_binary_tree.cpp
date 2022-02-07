#include <iostream>

#include "map.hpp"
#include <map>

#include <cstdlib>
#include <random>

int main()
{
    std::cout << "* * *    \033[1;32mbinary_tree\033[0m   * * *" << std::endl << std::endl;

    binary_tree<int> bt = binary_tree<int>();

    std::cout << "\n-> insertion:\n" << std::endl;

    bt.insert(3);
    std::cout << "insert: 3" << std::endl;
    bt.insert(4);
    std::cout << "insert: 4" << std::endl;
    bt.insert(9);
    std::cout << "insert: 9" << std::endl;
    bt.insert(1);
    std::cout << "insert: 1" << std::endl;
    bt.insert(5);
    std::cout << "insert: 5" << std::endl;
    bt.insert(7);
    std::cout << "insert: 7" << std::endl;
    bt.insert(10);
    std::cout << "insert: 10" << std::endl;
    bt.insert(12);
    std::cout << "insert: 12" << std::endl;
    bt.insert(2);
    std::cout << "insert: 2" << std::endl;
    bt.insert(6);
    std::cout << "insert: 6" << std::endl;
    bt.insert(8);
    std::cout << "insert: 8" << std::endl;
    bt.insert(18);
    std::cout << "insert: 18" << std::endl;
    bt.insert(11);
    std::cout << "insert: 11" << std::endl;
    bt.insert(13);
    std::cout << "insert: 13" << std::endl;
    bt.insert(16);
    std::cout << "insert: 16" << std::endl;
    bt.insert(19);
    std::cout << "insert: 19" << std::endl;
    bt.insert(14);
    std::cout << "insert: 14" << std::endl;
    bt.insert(20);
    std::cout << "insert: 20" << std::endl;
    bt.insert(15);
    std::cout << "insert: 15" << std::endl;
    bt.insert(17);
    std::cout << "insert: 17" << std::endl;
    bt.insert(12);
    std::cout << "insert: 12" << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();

    std::cout << "\n-> insertion of already existing element:\n" << std::endl;
    bt.insert(11);
    std::cout << "insert: 11" << std::endl;
    bt.insert(13);
    std::cout << "insert: 13" << std::endl;
    bt.insert(16);
    std::cout << "insert: 16" << std::endl;
    bt.insert(19);
    std::cout << "insert: 19" << std::endl;
    bt.insert(14);
    std::cout << "insert: 14" << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();

    std::cout << "\n-> try loop on it with any iterators:\n" << std::endl;
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); it++)
    {
        std::cout << "reverse_value++: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); it++)
    {
        std::cout << "value++        : " << *it << std::endl;
    }
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); ++it)
    {
        std::cout << "++reverse_value: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); ++it)
    {
        std::cout << "++value        : " << *it << std::endl;
    }

    std::cout << "\n-> erase unknown data:\n" << std::endl;
    bt.erase(42);
    std::cout << "erase: " << 42 << std::endl;
    bt.erase(101);
    std::cout << "erase: " << 101 << std::endl;
    bt.erase(420);
    std::cout << "erase: " << 420 << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();


    std::cout << "\n-> erase actual data:\n" << std::endl;

    bt.erase(5);
    std::cout << "erase: " << 5 << std::endl;
    bt.erase(4);
    std::cout << "erase: " << 4 << std::endl;
    bt.erase(1);
    std::cout << "erase: " << 1 << std::endl;
    bt.erase(2);
    std::cout << "erase: " << 2 << std::endl;
    bt.erase(3);
    std::cout << "erase: " << 3 << std::endl;
    bt.erase(9);
    std::cout << "erase: " << 9 << std::endl;
    bt.erase(8);
    std::cout << "erase: " << 8 << std::endl;
    bt.erase(7);
    std::cout << "erase: " << 7 << std::endl;
    bt.erase(6);
    std::cout << "erase: " << 6 << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();

    bt.erase(20);
    std::cout << "erase: " << 20 << std::endl;
    bt.erase(19);
    std::cout << "erase: " << 19 << std::endl;
    bt.erase(17);
    std::cout << "erase: " << 17 << std::endl;
    bt.erase(18);
    std::cout << "erase: " << 18 << std::endl;
    bt.erase(16);
    std::cout << "erase: " << 16 << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();

    std::cout << "\n+ try loop on it half deleted with any iterators\n" << std::endl;
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); it++)
    {
        std::cout << "reverse_value++: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); it++)
    {
        std::cout << "value++        : " << *it << std::endl;
    }
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); ++it)
    {
        std::cout << "++reverse_value: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); ++it)
    {
        std::cout << "++value        : " << *it << std::endl;
    }

    std::cout << "\n-> continue erasing\n" << std::endl;

    bt.erase(15);
    std::cout << "erase: " << 15 << std::endl;
    bt.erase(10);
    std::cout << "erase: " << 10 << std::endl;
    bt.erase(13);
    std::cout << "erase: " << 13 << std::endl;
    bt.erase(14);
    std::cout << "erase: " << 14 << std::endl;
    bt.erase(12);
    std::cout << "erase: " << 12 << std::endl;
    bt.erase(11);
    std::cout << "erase: " << 11 << std::endl;

    std::cout << "printing tree: " << std::endl;
    bt.print();

    std::cout << "\n-> try loop on it with any iterators (nothing = OK)" << std::endl;
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); it++)
    {
        std::cout << "reverse_value++: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); it++)
    {
        std::cout << "value++        : " << *it << std::endl;
    }
    for (binary_tree<int>::reverse_iterator it = bt.rbegin(); it != bt.rend(); ++it)
    {
        std::cout << "++reverse_value: " << *it << std::endl;
    }
    for (binary_tree<int>::iterator it = bt.begin(); it != bt.end(); ++it)
    {
        std::cout << "++value        : " << *it << std::endl;
    }
    return (0);
}

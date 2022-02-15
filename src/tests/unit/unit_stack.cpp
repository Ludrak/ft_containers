
#include <stack>
#include "stack.hpp"

#include "unit_test.hpp"
#include "containers_test.hpp"

#include <iostream>

namespace LIB = LIBRARY;

void unit_stack()
{
    std::cout << "* * *    \033[1;32mSTACK\033[0m   * * *" << std::endl << std::endl;

    {
        UNIT_START("stack member functions")

        UNIT_TEST("stack::stack()")
            LIB::stack<int> s = LIB::stack<int>();
        
        UNIT_TEST("stack::empty()")
            if (!s.empty())
            {
                UNIT_ERROR("empty: empty map not counted empty");
            }
            s.push(1);
            s.push(2);
            s.push(3);
            if (s.empty())
            {
                UNIT_ERROR("empty: non-empty map counted empty");
            }
        
        UNIT_TEST("stack::size()")
            if (s.size() != 3)
            {
                UNIT_ERROR("size: size does not match " << s.size() << " expected " << 3);
            }
        
        UNIT_TEST("stack::top()")
            if (s.top() != 3)
            {
                UNIT_ERROR("top: top value does not match " << s.top() << " expecting 3")
            }
            s.push(0);
            if (s.top() != 0)
            {
                UNIT_ERROR("top: top value does not match " << s.top() << " expecting 0")
            }
        
        UNIT_TEST("stack::push()")
            s.push(42);
            if (s.top() != 42)
            {
                UNIT_ERROR("push: top value does not match " << s.top() << " expecting 42")
            }
            s.push(101);
            if (s.top() != 101)
            {
                UNIT_ERROR("push: top value does not match " << s.top() << " expecting 101")
            }
        
        UNIT_TEST("stack::pop()")
            s.pop();
            if (s.top() != 42)
            {
                UNIT_ERROR("pop: top value does not match " << s.top() << " expecting 42")
            }
            s.pop();
            if (s.top() != 0)
            {
                UNIT_ERROR("pop: top value does not match " << s.top() << " expecting 0")
            }
        
        UNIT_END
    }

    {
        UNIT_START("stack operators")
            UNIT_TEST("stack::operator=()")
                LIB::stack<int> stk = LIB::stack<int>();
                LIB::stack<int> stk2 = LIB::stack<int>();
                stk2.push(1);
                stk2.push(2);
                stk2.push(3);
                stk = stk2;
                if (stk.top() != 3)
                {
                    UNIT_ERROR("stack::operator= : no/partial copy of stack");
                }

            UNIT_TEST("stack::operator==()")
                if (!(stk == stk2))
                {
                    UNIT_ERROR("operator== : equals stacks are not equals");
                }

            UNIT_TEST("stack::operator!=()")
                if (stk != stk2)
                {
                    UNIT_ERROR("operator!= : equals stacks are different");
                }

            UNIT_TEST("stack::operator<=()")
                if (!(stk <= stk2))
                {
                    UNIT_ERROR("operator<= : equals stacks are not equals");
                }
                stk2.pop();
                if (stk <= stk2)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }


            UNIT_TEST("stack::operator<()")
                if (stk < stk2)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }

            UNIT_TEST("stack::operator>=()")
                stk2.push(3);
                if (!(stk >= stk2))
                {
                    UNIT_ERROR("operator<= : equals stacks are not equals");
                }
                stk2.pop();
                if (stk2 >= stk)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }

            UNIT_TEST("stack::operator>()")
                if (stk2 > stk)
                {
                    UNIT_ERROR("operator<= : order not respected");
                }
        UNIT_END
    }
}
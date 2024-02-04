#include <iostream>
#include <functional>

#include "stack.hpp"
#include "stack_enhanced.hpp"
#include "stack_rpn.hpp" // Put your code in this file


int main(int argc, char **argv)
{
    // Basic interface
    auto stack = StackEnhanced<int>(100);
    stack.push(2);
    stack.push(2);
    stack.push(3);
    plus(stack);
    multiplies(stack);
    std::cout << "2 2 2 + * = " << stack.top() << '\n';

    // Advanced interface (optional)
    stack << 2 << 2 << 3 << plus;
    std::cout << "2 2 2 + * = " << stack.top() << '\n';

    return 0;
}

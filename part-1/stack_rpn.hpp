#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE
//plus
template <typename T>
void plus(StackEnhanced<T>& stack)
{
    T a = stack.tpop();
    T b = stack.tpop();
    stack.push(a+b);
}

//minus
template <typename T>
void minus(StackEnhanced<T>& stack)
{
    T a = stack.tpop();
    T b = stack.tpop();
    stack.push(a-b);
}


//multiplies
template <typename T>
void multiplies(StackEnhanced<T>& stack)
{
    T a = stack.tpop();
    T b = stack.tpop();
    stack.push(a*b);
}

//divides
template <typename T>
void divides(StackEnhanced<T>& stack)
{
    T a = stack.tpop();
    T b = stack.tpop();
    stack.push(a/b);
}

//negates
template <typename T>
void negates(StackEnhanced<T>& stack)
{
    T a = stack.tpop();
    stack.push(-1*a);
}

template <typename T> class StackEnhanced2 : public StackEnhanced<T>
{
    public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;
};

/*
template <typename T>
std::function<void()> multiplies_ = [&]()
{
    T a = stack.tpop();
    T b = stack.tpop();
    stack.push(a*b);
};
*/

/*
auto plus_ = [](auto& stack)
{
    auto a = stack.tpop();
    auto b = stack.tpop();
    stack.push(a+b);
};
*/

#endif // __stack_rpn__
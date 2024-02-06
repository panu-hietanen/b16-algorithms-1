#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include "stack_enhanced.hpp"
#include <cassert>
#include <functional>

// WRITE YOUR CODE HERE
//plus

void adder(StackEnhanced<int>& stack)
{
    int a = stack.tpop();
    int b = stack.tpop();
    stack.push(a+b);
}

//minus
void take_away(StackEnhanced<int>& stack)
{
    int a = stack.tpop();
    int b = stack.tpop();
    stack.push(a-b);
}


//multiplies
void multiply(StackEnhanced<int>& stack)
{
    int a = stack.tpop();
    int b = stack.tpop();
    stack.push(a*b);
}

//divides
void divide(StackEnhanced<int>& stack)
{
    int a = stack.tpop();
    int b = stack.tpop();
    stack.push(a/b);
}

//negates
void negate(StackEnhanced<int>& stack)
{
    int a = stack.tpop();
    stack.push(-1*a);
}

std::function<void(StackEnhanced<int>&)> plus = adder;
std::function<void(StackEnhanced<int>&)> multiplies = multiply;
std::function<void(StackEnhanced<int>&)> minus = take_away;
std::function<void(StackEnhanced<int>&)> divides = divide;
std::function<void(StackEnhanced<int>&)> negates = negate;

#endif // __stack_rpn__
#ifndef __stack_enhanced___
#define __stack_enhanced___

#include "stack.hpp"
#include <functional>

template <typename T> class StackEnhanced : public Stack<T>
{
  public:
    // Inherit the Stack<T> constructors as they are
    // https://en.cppreference.com/w/cpp/language/using_declaration
    using Stack<T>::Stack;

    void clear()
    {
        // WRITE YOUR CODE HERE
        this->_head = 0;
    }

    T &tpop()
    {
        assert(this->_head > 0);
        T a = this->top();
        this->pop();
        return a;
    }


    StackEnhanced<T> rpn(std::function<StackEnhanced<int>(StackEnhanced<int>)> operation)
    {
        this->push(operation(*this));
        return *this;
    }

    StackEnhanced<int> &operator<<(std::function<void(StackEnhanced<int>)> func)
    {
        this->rpn(func);
        return *this;
    }
};

/*
std::function<StackEnhanced<int>(StackEnhanced<int>)> plus_ = [](StackEnhanced<int> stack) 
{
    int a = stack.tpop();
    int b = stack.tpop();
    stack.push(a+b);
};
*/

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T> &stack, const T &value)
{
    // WRITE YOUR CODE HERE
    stack.push(value);
    return stack;
}

#endif // __stack_enhanced___
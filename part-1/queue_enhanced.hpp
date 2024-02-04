#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        assert(!this->full());
        size_t i;
        if (this->empty())
        {
            i = 0;
            this->_position = this->_storage.size() - 1;
        } else
        {
            i = this->_head() + 1;
        }
        if (i > this->_storage.size())
        {
            i -= this->_storage.size();
        }
        this->_size++;
        this->_storage[i] = value; 
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        // WRITE YOUR CODE HERE
        assert(!this->empty());
        if (this->_tail() == this->_head())
        {
            this->clear();
        } else
        {
        this->_size--;
        this->_position++;
        }
    }

    // Remove all elements from the queue
    void clear() { 
        // WRITE YOUR CODE HERE
        this->_size = 0;
        this->_position = 0;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        // WRITE YOUR CODE HERE
        int t = this->_head() - this->_size + 1;
        if (t < 0)
        {
            t += this->_storage.size();
        }
        return static_cast<size_t>(t);
    }
};

#endif // __queue_enhanced__
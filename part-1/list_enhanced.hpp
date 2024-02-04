
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    node->next = std::move(node->next->next);
}

#endif // __list_enhanced__
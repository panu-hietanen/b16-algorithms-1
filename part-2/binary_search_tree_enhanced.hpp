#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    return left(tree) ? bst_min(left(tree)) : tree;
}

template <typename T> T bst_max(const T &tree)
{
    return right(tree) ? bst_max(right(tree)) : tree;
}

#endif // __binary_saerch_tree_enhanced__
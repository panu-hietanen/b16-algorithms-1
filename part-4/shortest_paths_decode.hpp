#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>
#include <deque>

inline std::vector<int> decode_(const std::vector<hop_t> &DP, int v)
{
    std::vector<int> res;
    int start = -1;
    for (int i = 0; i < DP.size(); ++i)
    {
        if (DP[i].weight == 0)
        {
            start = i;
            break;
        }
    }
    if (v == start || DP[v].weight == inf)
    {
        return res;
    }
    int v_test = v;
    std::deque<int> d;
    d.push_back(v);
    bool found = false;
    while (!found)
    {
        if (DP[v_test].vertex == start)
        {
            if (v_test != v) { d.push_front(v_test); }
            found = true;
        }
        else
        {
            if (v_test != v) { d.push_front(v_test); }
            v_test = DP[v_test].vertex;
        }
    }
    d.push_front(start);
    for (auto i = d.begin(); i != d.end(); ++i)
    {
        res.push_back(*i);
    }
    return res;
}

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    if (DP[v].vertex == -1)
    {
        return {};
    }
    std::deque<int> d;
    int v_curr = v;
    while (DP[v_curr].weight != 0)
    {
        d.push_front(v_curr);
        v_curr = DP[v_curr].vertex;
        if (v_curr == -1)
        {
            return {};
        }
    }
    if (v_curr != -1)
    {
        d.push_front(v_curr);
    }
    return std::vector<int>(d.begin(), d.end());
}

#endif // __shortest_paths_decode__

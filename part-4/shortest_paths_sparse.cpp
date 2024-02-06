#include "shortest_paths_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight = 0;

    // Iterate V-1 times
    for (int i = 0; i < V-1; ++i)
    {
        has_negative_cycle = false;
        // For each pair of vertices 
        for (int r = 0; r < V; ++r)
        {
            for (int v = 0; v < V; ++v)
            {
                float test_weight = inf;
                for (auto iter : graph[r]) { if (iter.vertex == v) { test_weight = iter.weight; } }
                auto Duv = DP[v].weight;
                auto Duv_via_r = DP[r].weight + test_weight;
                if (Duv_via_r < Duv)
                {
                    DP[v] = {Duv_via_r, r};
                    has_negative_cycle |= true;
                }
                else { has_negative_cycle |= false; }
            }
        }
    }
    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra_(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight = 0;

    std::vector<bool> is_open(V, true);

    while (true)
    {
        float D_star = inf;
        int v_star = -1;
        for (int v = 0; v < V; ++v)
        {
            if (is_open[v] && DP[v].weight < D_star)
            {
                D_star = DP[v].weight;
                v_star = v;
            }
        }
        if (v_star < 0) { break; }

        is_open[v_star] = false;

        for (int v = 0; v < V; ++v) 
        {
            float test_weight = inf;
            for (auto iter : graph[v_star]) 
            { if (iter.vertex == v) { test_weight = iter.weight; } }
            if (is_open[v] && std::isfinite(test_weight)) 
            {

                auto Duv = DP[v].weight;
                auto Duv_via_r = DP[v_star].weight + test_weight;
                if (Duv_via_r < Duv)
                {
                    DP[v] = {Duv_via_r, v_star};
                }
            }
        }
    }


    return DP;
}

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight = 0;

    auto queue = std::vector<hop_t>{};
    auto comparison = std::less<hop_t>{};
    priority_enqueue(queue, {0, source}, comparison);

    while (!queue.empty())
    {
        int v_star = queue[0].vertex;
        priority_dequeue(queue, comparison);

        for (int v = 0; v < V; ++v) 
        {
            float test_weight = inf;
            for (auto iter : graph[v_star]) { if (iter.vertex == v) { test_weight = iter.weight; } }
            if (std::isfinite(test_weight)) 
            {
                auto Duv = DP[v].weight;
                auto Duv_via_r = DP[v_star].weight + test_weight;
                if (Duv_via_r < Duv)
                {
                    DP[v] = {Duv_via_r, v_star};
                    priority_enqueue(queue, {DP[v].weight, v}, comparison);
                }
            }
        }
    }


    return DP;
}
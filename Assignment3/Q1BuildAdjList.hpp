#ifndef Q1BUILDADJLIST_HPP
#define Q1BUILDADJLIST_HPP

#include <bits/stdc++.h>

class AdjList {
    public:
        map<int, vector<int>> buildAdjacencyList(vector<pair<int, int>>& edges);
        bool bfs(int target, map<int, set<int>> graph);
        bool dfs(int target, map<int, set<int>> graph);
        array<int> topologicalSort(map<int, set<int>> graph);
    private:
};

#endif
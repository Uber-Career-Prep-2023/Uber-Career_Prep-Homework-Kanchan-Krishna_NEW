#include "Q1BuildAdjList.hpp"
#include <bits/stdc++.h>
/*
Given an array of pairs of values representing edges in an unweighted graph, create the equivalent adjacency list/set representation (a map from element to a list or set of elements). Pairs represent directed edges: (A, B) means there is an edge from A to B. If the pair (B, A) is also provided then there is an undirected edge between A and B. For simplicity, you may assume that each node of the graph stores an integer rather than a generic data type and that the elements are distinct. Implement a basic DFS and BFS searching for a target value and a topological sort (using either DFS or Kahn’s algorithm).
*/

/*
Time Complexity:
Space Complexity:
Time Taken:
Technique Used:
*/

/*
Example
Input: [(1, 2), (2, 3), (1, 3), (3, 2), (2, 0)]
Output:
{
    0: []
    1: [2, 3]
    2: [0, 3]
    3: [2]
}
*/

map<int, vector<int>> buildAdjacencyList(vector<pair<int, int>>& edges) {
    map<int, vector<int>> adj_list; 
    for (int i = 0; i < edges.size(); i++) {
        pair<int, int> p = edges[i];
        int start = p.first; 
        int end = p.second; 
        if (adj_list.find(start) == adj_list.end()) {
            vector<int> neighbors;
            neighbors.push_back(end);
            adj_list[start] = neighbors;
        } else {
            vector<int> neighbors = adj_list[start];
            neighbors.push_back(end);
            adj_list[start] = neighbors; 
        }
    }
    return adj_list; 
}
bool bfs(int target, map<int, set<int>> graph);
bool dfs(int target, map<int, set<int>> graph);
array<int> topologicalSort(map<int, set<int>> graph);

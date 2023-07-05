#include <bits/stdc++.h>
using namespace std;

/*
Given an array of pairs of values representing edges in an unweighted graph, create the equivalent adjacency list/set representation (a map from element to a list or set of elements). Pairs represent directed edges: (A, B) means there is an edge from A to B. If the pair (B, A) is also provided then there is an undirected edge between A and B. For simplicity, you may assume that each node of the graph stores an integer rather than a generic data type and that the elements are distinct. Implement a basic DFS and BFS searching for a target value and a topological sort (using either DFS or Kahn’s algorithm).
*/

vector<vector<int>> buildAdj(vector<pair<int, int>> edges) {
    vector<vector<int>> adj; 
    for (auto& edge : edges) {
        int node_A = edge.first; 
        int node_B = edge.second;
        adj[node_A].push_back(node_B);
        adj[node_B].push_back(node_A);
    }
    return adj; 
}

int main() {
    vector<pair<int, int>> edges_list = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    vector<vector<int>> adj = buildAdj(edges_list);
    for (auto& edge : adj) {
        for (auto& n : edge) {
            cout << "Node: " << n << " "; 
        }
        cout << endl;
    }
}
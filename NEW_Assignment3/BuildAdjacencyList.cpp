#include <bits/stdc++.h>
using namespace std;

/*
Given an array of pairs of values representing edges in an unweighted graph, create the equivalent adjacency list/set representation (a map from element to a list or set of elements). Pairs represent directed edges: (A, B) means there is an edge from A to B. If the pair (B, A) is also provided then there is an undirected edge between A and B. For simplicity, you may assume that each node of the graph stores an integer rather than a generic data type and that the elements are distinct. Implement a basic DFS and BFS searching for a target value and a topological sort (using either DFS or Kahn’s algorithm).
*/

vector<vector<int>> buildAdj(vector<pair<int, int>> edges)
{
    // cout << "Size of edges: " << edges.size() << endl;
    // create a set of nodes (distinct)
    set<int> nodes;
    for (auto &e : edges)
    {
        nodes.insert({e.first});
        nodes.insert({e.second});
    }
    vector<vector<int>> adj(nodes.size());
    for (auto &edge : edges)
    {
        int node_A = edge.first;
        int node_B = edge.second;
        // cout << "Node A: " << node_A << " Node B: " << node_B << endl;
        adj[node_A].push_back(node_B);
    }
    // cout << endl;
    return adj;
}

bool bfs(int target, int start_node, vector<pair<int, int>> edges)
{
    vector<vector<int>> graph = buildAdj(edges);
    set<int> nodes;
    for (auto &e : edges)
    {
        nodes.insert({e.first});
        nodes.insert({e.second});
    }
    cout << "Printing set: " << endl;
    for (auto &node : nodes)
    {
        cout << node << " ";
    }
    cout << endl;
    vector<bool> visited(nodes.size(), false);
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == target)
        {
            return true;
        }
        for (auto &neighbor : graph[curr])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return false;
}

// bool dfs(int target, int start_node, vector<pair<int, int>> edges);
vector<int> topologicalSort(vector<vector<int>> graph);

int main()
{
    vector<pair<int, int>> edges_list = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    vector<vector<int>> adj = buildAdj(edges_list);
    for (int i = 0; i < adj.size(); i++)
    {
        cout << "Neighbors of (i - curr node): " << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Using BFS to find node 2" << endl;
    bool found_bfs = bfs(2, 0, edges_list);
    if (found_bfs)
    {
        cout << "Found the value" << endl;
    }
    else
    {
        cout << "Could not find value" << endl;
    }
    // bool found_dfs = dfs(2, 0, edges_list);
    // if (found_dfs) {
    //     cout << "Found the value" << endl;
    // } else {
    //     cout << "Could not find value" << endl;
    // }
}
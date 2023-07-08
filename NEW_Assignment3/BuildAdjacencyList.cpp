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

bool bfs(vector<vector<int>> edges, int start_node, int target) {
    int count = edges.size();
    vector<bool> visited(count, false);
    queue<int> q;
    visited[start_node] = true;
    q.push(start_node);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == target)
        {
            return true;
        }
        for (int neighbor : edges[curr])
        {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

bool dfs(vector<vector<int>> edges, int start_node, int target, vector<bool>& visited) {
    visited[start_node] = true;
    if (start_node == target)
    {
        return true;
    }
    for (int neighbor : edges[start_node])
    {
        if (!visited[neighbor])
        {
            bool found = dfs(edges, neighbor, target, visited);
            if (found)
            {
                return true;
            }
        }
    }
    return false;
}

bool dfsMain(vector<vector<int>> graph, int start_node, int target) {
    int count = graph.size();
    vector<bool> visited(count, false);
    return dfs(graph, start_node, target, visited);
}

vector<int> topologicalSort(vector<vector<int>> edges) {
    int count = edges.size();
    vector<int> in_degree(count, 0);
    vector<vector<int>> adj(count);
    for (int i = 0; i < count; i++) {
        for (int neighbor : edges[i])
        {
            ++in_degree[neighbor];
            adj[i].push_back(neighbor);
        }
    }
    queue<int> q;
    for (int i = 0; i < count; ++i) {
        if (in_degree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int neighbor : adj[curr]) {
            --in_degree[neighbor];
            if (in_degree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    return res;
}

int main() {
    vector<pair<int, int>> edges_list = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    vector<vector<int>> adj = buildAdj(edges_list);
    for (int i = 0; i < adj.size(); i++) {
        cout << "Neighbors of (i - curr node): " << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Using BFS to find node 2" << endl;
    int start_node = 0;
    int find_val = 2;
    bool found_bfs = bfs(adj, start_node, find_val);
    if (found_bfs) {
        cout << "Found the value" << endl;
    } else {
        cout << "Could not find value" << endl;
    }
    cout << "Using DFS to find node 2" << endl;
    bool found_dfs = dfsMain(adj, start_node, find_val);
    if (found_dfs)
    {
        cout << "Found the value" << endl;
    }
    else
    {
        cout << "Could not find value" << endl;
    }
    vector<int> res = topologicalSort(adj);
    cout << "Topological Ordering: " << endl;
    for (auto ele : res) {
        cout << "Node: " << ele << endl;
    }
}
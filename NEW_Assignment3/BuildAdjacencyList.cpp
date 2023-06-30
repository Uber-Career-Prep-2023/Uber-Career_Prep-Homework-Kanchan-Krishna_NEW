#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(E) where e is the # of edges
//Space Complexity: O(V + E) where e is # of edges and v is # of vertices
map<int, set<int>> buildAdjGraph(vector<pair<int, int>>& edges) {
    map<int, vector<int>> adj;
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
    }
    return adj;
}

//Time Complexity: O(V + E)
//Space Complexity: O(V)
bool bfs(int val, map<int, set<int>> adj) {
    queue<int> q;
    q.push(adj.begin()->first);
    set<int> visited_nodes;
    visited_nodes.insert(adj.begin()->first);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == val)
        {
            return true;
        }
        for (auto neighbor : adj[curr]) { //now visit all of curr's neighbors
            if (visited_nodes.find(neighbor) == visited_nodes.end())
            {
                q.push(neighbor);
                visited_nodes.insert(neighbor);
            }
        }
    }
    return false;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
bool dfs(int val, map<int, set<int>> adj) {
    set<int> visited_nodes;
    stack<int> st;
    st.push(val);
    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (visited_nodes.count(curr) > 0) { //ignore 
            continue;
        }
        visited_nodes.insert(curr);
        for (auto neighbor : adj[curr]) {
            if (visited_nodes.count(neighbor) == 0) {
                st.push(neighbor); //has not been processed yet
            }
        }
    }
    return visited_nodes.count(val) > 0;
}

// Time Complexity: O(V + E)
// Space Complexity: O(V)
void topologicalHelper(int curr, map<int, set<int>>& adj, stack<int>& visited_nodes, map<int, bool>& visited) {
    visited[curr] = true;
    for (auto neighbor : adj[curr]) {
        if (!visited[neighbor]) {
            topologicalHelper(neighbor, adj, visited_nodes, visited);
        }
    }
    visited_nodes.push(curr);
}

vector<int> topologicalSort(map<int, set<int>> adj) {
    stack<int> visited_nodes;
    map<int, bool> visited;
    topologicalHelper(adj.begin()->first, adj, visited_nodes, visited);
    vector<int> res;
    while (!visited_nodes.empty())
    {
        res.push_back(visited_nodes.top());
        visited_nodes.pop();
    }
    return res;
}

int main() {
    vector<pair<int, int>> edges_list = {{1, 2}, {2, 3}, {1, 3}, {3, 2}, {2, 0}};
    map<int, set<int>> adj = buildAdjGraph(edges_list);
    for (auto ele : adj) {
        cout << ele.first << " ";
        for (auto neighbor : ele.second) { //neighbors 
            cout << neighbor << " ";
        }
        cout << "" << endl;
    }
    cout << bfs(1, adj) << endl;
    cout << dfs(1, adj) << endl;
    vector<int> res = topologicalSort(adj);
    for (auto ele : res) {
        cout << ele << " ";
    }
}
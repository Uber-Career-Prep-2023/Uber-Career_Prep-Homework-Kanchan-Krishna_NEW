// Given an origin city, a maximum travel time k, and pairs of destinations that can be reached directly from each other with corresponding travel times in hours, return the number of destinations within k hours of the origin. Assume that having a stopover in a city adds an hour of travel time.

/*
Time Complexity: O(V*E)
Space Complexity: O(V*E)
Time Taken: 40 min
Technique Used: Keep track of the shortest distance 
*/

#include <bits/stdc++.h>
using namespace std; 

map<string, vector<pair<string, double>>> createAdjacencyMap(vector<pair<string, string>> edges, vector<double> weights_list) {
    map<string, vector<pair<string, double>>> adj;
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i].first].push_back({edges[i].second, weights_list[i]});
        adj[edges[i].second].push_back({edges[i].first, weights_list[i]});
    }
    return adj;
}

void dfs(string curr, int k, map<string, vector<pair<string, double>>>& adj, map<string, double>& paths) {
    for (int i = 0; i < adj[curr].size(); i++) {
        bool shortest1 = !paths.count(adj[curr][i].first) && adj[curr][i].second + paths[curr] <= k;
        bool shortest2 = paths.count(adj[curr][i].first) && paths[adj[curr][i].first] > paths[curr] + adj[curr][i].second;
        if (shortest1 || shortest2) {
            paths[adj[curr][i].first] = adj[curr][i].second + paths[curr] + 1;
            dfs(adj[curr][i].first, k, adj, paths);
        }
    }
}

int shortestPath(vector<pair<string, string>> edges, vector<double> weights_list, string start, int k) {
    map<string, vector<pair<string, double>>> adj = createAdjacencyMap(edges, weights_list);
    map<string, double> shortestPath;
    shortestPath[start] = 0;
    dfs(start, k, adj, shortestPath);
    return shortestPath.size() - 1;
}

int main() {
    vector<pair<string, string>> edges1 = {{"Boston", "New York"}, {"New York", "Philadelphia"}, {"Boston", "Newport"}, {"Washington, D.C.", "Harper's Ferry"}, {"Boston", "Portland"}, {"Philadelphia", "Washington, D.C."}};
    vector<double> weights1 = {4, 2, 1.5, 1, 2.5, 2.5};
    cout << shortestPath(edges1, weights1, "New York", 5) << endl;
}
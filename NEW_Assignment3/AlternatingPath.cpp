//Given an origin and a destination in a directed graph in which edges can be blue or red, determine the length of the shortest path from the origin to the destination in which the edges traversed alternate in color_type.Return - 1 if no such path exists.

/*
Time Complexity: O(n + m) => visiting all nodes and edges in the graph
Time Taken: 45 min
Technique Used: BFS
*/

#include <bits/stdc++.h>
using namespace std;

struct edgesStruct {
    char first_node;
    char second_node;
    string color;
};

struct nodeType {
    char node;
    string color;
    int shortestPath;
};

struct mapType {
    char node;
    string color;
};

int alternatingPath(map<char, vector<mapType>> adj, char og, char dest)
{
    queue<nodeType> q;
    map<pair<char, string>, bool> visited;
    q.push({og, "-", 0});
    visited[{og, "-"}] = true;
    while (!q.empty()) {
        nodeType curr = q.front();
        q.pop();
        if (curr.node == dest) {
            return curr.shortestPath;
        }
        for (auto neighbor : adj[curr.node])
        {
            if (!visited[{neighbor.node, curr.color}] && curr.color != neighbor.color)
            {
                q.push({neighbor.node, neighbor.color, curr.shortestPath + 1});
                visited[{neighbor.node, curr.color}] = true;
            }
        }
    }
    return -1;
}

map<char, vector<mapType>> createAdjList(vector<edgesStruct> &edges)
{
    map<char, vector<mapType>> adj;
    for (auto edge : edges) {
        adj[edge.first_node].push_back({edge.second_node, edge.color});
    }
    return adj;
}

void printOutput(int sp, char og, char d) {
    cout <<  og << " " << sp << " " << d << endl;
}

int main() {
    vector<edgesStruct> edges =
    {{'A', 'B', "blue"}, {'A', 'C', "red"}, {'B', 'D', "blue"}, {'B', 'E', "blue"}, {'C', 'B', "red"}, {'D', 'C', "blue"}, {'A', 'D', "red"}, {'D', 'E', "red"}, {'E', 'C', "red"}};
    printOutput(alternatingPath(createAdjList(edges), 'A', 'E'), 'A', 'E');
    printOutput(alternatingPath(createAdjList(edges), 'E', 'D'), 'E', 'D');
    printOutput(alternatingPath(createAdjList(edges), 'E', 'E'), 'E', 'E');
    printOutput(alternatingPath(createAdjList(edges), 'B', 'C'), 'B', 'C');
}
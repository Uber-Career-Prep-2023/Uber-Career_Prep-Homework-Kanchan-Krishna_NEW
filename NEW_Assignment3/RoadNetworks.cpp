//In some states, it is not possible to drive between any two towns because they are not connected to the same road network.Given a list of towns and a list of pairs representing roads between towns, return the number of road networks.(For example, a state in which all towns are connected by roads has 1 road network, and a state in which none of the towns are connected by roads has 0 road networks.)

/*
Time Complexity: O(V + E)
Space Complexity: O (V + E)
Time Taken: 40 min
Technique Used: Hashing then Depth First Search
*/

#include <bits/stdc++.h>
using namespace std; 

map<string, vector<string>> adjacencySet(vector<pair<string, string>>& road) {
    map<string, vector<string>> m;
    for (int i = 0; i < road.size(); i++) {
        //consider both directions
        m[road[i].first].push_back(road[i].second);
        m[road[i].second].push_back(road[i].first);
    }
    return m;
}

void dfs(int city_idx, map<string, int>& destination, map<string, vector<string>>& adj, vector<string>& cities_list) {
    string city = cities_list[city_idx];
    cities_list[city_idx] = "*";
    for (int i = 0; i < adj[city].size(); i++) {
        int index = destination[adj[city][i]];
        if (cities_list[index] != "*")
        {
            dfs(index, destination, adj, cities_list);
        }
    }
}

int RoadNetwork(vector<string>& cities_list, vector<pair<string, string>>& roads_list) {
    map<string, vector<string>> adj = adjacencySet(roads_list);
    map<string, int> dest;
    for (int i = 0; i < cities_list.size(); i++)
    {
        dest[cities_list[i]] = i;
    }
    int sum = 0;
    for (int i = 0; i < cities_list.size(); i++)
    {
        if (cities_list[i] != "*" && adj[cities_list[i]].size() > 0)
        {
            dfs(i, dest, adj, cities_list);
            sum++;
        }
    }
    return sum;
}

int main() {
    vector<string> cities_list1 = {"Skagway", "Juneau", "Gustavus", "Homer", "Port Alsworth", "Glacier Bay", "Fairbanks", "McCarthy", "Copper Center", "Healy", "Anchorage"};
    vector<pair<string, string>> roads_list1 = {{"Anchorage", "Homer"}, {"Glacier Bay", "Gustavus"}, {"Copper Center", "McCarthy"}, {"Anchorage", "Copper Center"}, {"Copper Center", "Fairbanks"}, {"Healy", "Fairbanks"}, {"Healy", "Anchorage"}};
    cout << RoadNetwork(cities_list1, roads_list1) << endl;
    vector<string> cities_list2 = {"Kona", "Hilo", "Volcano", "Lahaina", "Hana", "Haiku", "Kahului", "Princeville", "Lihue", "Waimea"};
    vector<pair<string, string>> road_list2 = {{"Kona", "Volcano"}, {"Volcano", "Hilo"}, {"Lahaina", "Hana"}, {"Kahului", "Haiku"}, {"Hana", "Haiku"}, {"Kahului", "Lahaina"}, {"Princeville", "Lihue"}, {"Lihue", "Waimea"}};
    cout << RoadNetwork(cities_list2, road_list2);
}
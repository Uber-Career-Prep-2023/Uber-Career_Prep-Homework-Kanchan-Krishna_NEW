// Given a list of courses that a student needs to take to complete their major and a map of courses to their prerequisites, return a valid order for them to take their courses assuming they only take one course for their major at once.

/*
Time Complexity: O(V + E)
Space Complexity: O(V)
Time Taken: 40 min
Technique Used: Topological Sort
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(map<string, bool>& visited, map<string, vector<string>>& prereq_list, string curr_course, vector<string>& curr) {
    visited[curr_course] = true;
    for (int i = 0; i < prereq_list[curr_course].size(); i++)
    {
        if (!visited.count(prereq_list[curr_course][i]))
        {
            dfs(visited, prereq_list, prereq_list[curr_course][i], curr);
        }
    }
    curr.push_back(curr_course);
}

vector<string> PrerequisiteCourses(vector<string>& courses_list, map<string, vector<string>>& prereqs) {
    map<string, bool> track_visited;
    vector<string> v;
    for (int i = 0; i < courses_list.size(); i++)
    {
        if (!track_visited.count(courses_list[i]))
        { // not visited yet
            dfs(track_visited, prereqs, courses_list[i], v);
        }
    }
    return v;
}

void printOutput(vector<string> &v) {
    for (auto ele : v) {
        cout << ele << ", ";
    }
}

int main() {
    vector<string> courses1 = {"Intro to Programming", "Data Structures", "Advanced Algorithms", "Operating Systems", "Databases"};
    map<string, vector<string>> prereqs1 = {{"Data Structures", {"Intro to Programming"}}, {"Advanced Algorithms", {"Data Structures"}}, {"Operating Systems", {"Advanced Algorithms"}}, {"Databases", {"Advanced Algorithms"}}};
    vector<string> res1 = PrerequisiteCourses(courses1, prereqs1);
    printOutput(res1);
    cout << " " << endl;
    vector<string> courses2 = {"Intro to Writing", "Contemporary Literature", "Ancient Literature", "Comparative Literature", "Plays & Screenplays"};
    map<string, vector<string>> prereqs2 = {{"Contemporary Literature", {"Intro to Writing"}}, {"Ancient Literature", {"Intro to Writing"}}, {"Comparative Literature", {"Ancient Literature", "Contemporary Literature"}}, {"Plays & Screenplays", {"Intro to Writing"}}};
    vector<string> res2 = PrerequisiteCourses(courses2, prereqs2);
    printOutput(res2);
}
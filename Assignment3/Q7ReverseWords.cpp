#include <bits/stdc++.h>
using namespace std;
// Given a string, return the string with the order of the space - separated words reversed
/*
Time Complexity: O(N) where N is the # of letters in the string
Space Complexity: O(N) where N is the # of letters in the string -> influences how big your strings vector is going to be
*/
string reverseSpace(string s)
{
    // put each word into a vector then iterate through the vector backwards
    vector<string> strings;
    string curr = "";
    for (auto letter : s)
    {
        if (letter != '')
        {
            curr += letter;
        }
        else
        {
            strings.push_back(curr);
            curr = "";
        }
    }
    string reversed;
    for (auto word : strings)
    {
        reversed += word;
    }
    return reversed;
}
int main()
{
}
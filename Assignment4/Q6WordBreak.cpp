#include <bits/stdc++.h>
using namespace std; 

/*Given a string of characters without spaces and a dictionary of valid words, determine if it can be broken into a list of valid words by adding spaces. 
*/

bool wordBreak(vector<string> dict, string input) {
    unordered_set<string> word;
    for (auto& i : dict) {
        word.insert(i);
    }
    if (word.find(input) != word.end()) {
        return true;
    }
    bool dp[input.size() + 1];
    memset(dp, false, sizeof(dp));
    dp[input.size()] = true;
    string temp = "";
    for (int i = input.size() - 1; i >= 0; i--)
    {
        for (int j = i; j < input.size(); j++)
        {
            temp = temp + input[j];
            if (word.find(temp) != word.end() && dp[j + 1])
                dp[i] = true;
        }
        temp = "";
    }
    return dp[0];
}

int main() {
    vector<string> dict = {"elf", "go", "golf", "man", "manatee", "not", "note", "pig", "quip", "tee", "teen"};
    cout << wordBreak(dict, "mangolf") << endl; 
}
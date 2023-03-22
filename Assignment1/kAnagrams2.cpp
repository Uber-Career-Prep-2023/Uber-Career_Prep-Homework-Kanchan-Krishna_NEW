#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Technique: Hashing
Time Complexity: O(n + m) where n and m are the # of chars in word1 and word2 respectively
Space Complexity: O(n + m) where n and m are the # of chars in word1 and word2 respectively
*/

bool kAnagrams(string &word1, string &word2, int &k)
{
    if (word1.length() != word2.length())
    {
        return false;
    }
    map<char, int> word1_freq_map;
    for (auto ch1 : word1)
    {
        word1_freq_map[ch1]++;
    }
    map<char, int> word2_freq_map;
    for (auto ch2 : word2)
    {
        word2_freq_map[ch2]++;
    }
    int deficit_count = 0; 
    for (auto entry : word2_freq_map) {
        if (word1_freq_map.find(entry.first) != word1_freq_map.end()) {
            deficit_count++; 
        }
    return deficit_count == k; 
    //old way of doing so:
    // how do I know what letters are the deficits...maps are sorted by default...loop through the map that has more entries and keep a count of how many times a letter in the map that has more entries does NOT appear in the map that has fewer entries
    /*map<char, int> to_loop_through;
    map<char, int> check;
    if (word1_freq_map.size() >= word2_freq_map.size())
    {
        to_loop_through = word1_freq_map;
        check = word2_freq_map;
    }
    else
    {
        to_loop_through = word2_freq_map;
        check = word1_freq_map;
    }
    int deficit_count = 0;
    for (auto entry : to_loop_through)
    {
        if (check.find(entry.first) == check.end())
        {
            deficit_count++;
        }
    }
    if (deficit_count == k)
    {
        return true;
    }
    return false;*/
    //count either the extras or the deficits 
}

int main()
{
    /*string word1 = "apple";
    string word2 = "peach";
    int k = 1;*/
    /*string word1 = "cat";
    string word2 = "dog";
    int k = 3;*/
    /*string word1 = "debit curd";
    string word2 = "bad credit";
    int k = 1;*/
    /*string word1 = "baseball";
    string word2 = "basketball";
    int k = 2;*/
    struct input
    {
        string word1;
        string word2;
        int k;
    };
    vector<input> input_list;
    input_list.push_back({"apple", "peach", 1});
    input_list.push_back({"apple", "peach", 2});
    input_list.push_back({"cat", "dog", 3});
    input_list.push_back({"debit curd", "bad credit", 1});
    input_list.push_back({"baseball", "basketball", 2});
    vector<int> output_list;
    output_list.push_back(0);
    output_list.push_back(1);
    output_list.push_back(1);
    output_list.push_back(1);
    output_list.push_back(0);
    for (int i = 0; i < input_list.size(); i++)
    {
        input element = input_list[i];
        cout << (kAnagrams(element.word1, element.word2, element.k) == output_list[i]);
    }
    // output was 11111 meaning the comparison to the expected output was true so yay!
}

// This question took me 20 min - had some trouble with the implementation but understood the algo

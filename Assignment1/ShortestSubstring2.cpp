#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
Technique: Hashing, Sliding Window with two (four) pointers
*/

int shortestSubstring(string s, string t)
{
    if (t.length() > s.length())
    {
        return 0;
    }
    map<char, int> t_map;
    map<char, int>::iterator t_itr;
    for (auto ch : t)
    {
        t_map[ch]++;
    }
    int i = 0; // right
    int j = 0; // left
    int left = 0;
    int right = s.length() - 1;
    int min_length = s.length();
    int count = t_map.size();
    bool found = false;
    while (i < s.length())
    {
        char end_char = s[i];
        i++;
        t_itr = t_map.find(end_char);
        if (t_itr != t_map.end())
        {
            t_itr->second--;
            if (t_itr->second == 0)
            {
                count--;
            }
        }
        if (count > 0)
        { // not found a substr yet
            continue;
        }
        while (count == 0)
        { // rid unecessary chars
            char start_char = s[j];
            j++;
            t_itr = t_map.find(start_char);
            if (t_itr != t_map.end())
            {
                t_itr->second++;
                if (t_itr->second > 0)
                {
                    count++;
                }
            }
        }
        if (i - j < min_length)
        {
            left = j;
            right = i;
            min_length = i - j;
            found = true;
        }
    }
    string res;
    if (found == true)
    {
        for (int a = left - 1; a <= right - 1; a++)
        {
            res += s[a];
        }
    }
    return res.length();
}

int main()
{
    struct input
    {
        string word1;
        string required;
    } vector<input> input_list;
    input_list.push_back({"abracadabra", "abc"});
    input_list.push_back({"zxycbaabcdwxyzzxwdcbxyzabccbazyx", "zzyzx"});
    input_list.push_back({"dog", "god"});
    vector<int> output_list;
    output_list.push_back(4);
    output_list.push_back(10);
    output_list.push_back(3);
    for (int i = 0; i < input_list.size(); i++)
    {
        vector<input> curr_input = input_list[i];
        if (shortestSubstring(curr_input.word1, curr_input.required) == output_list[i])
        {
            cout << "Passed!" << endl;
        }
    }
}

// This question took me 35 minutes
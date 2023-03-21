#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(n / 2) ?
Space Complexity: O(1)
Technique: Two Pointers
*/

bool isVowel(char c)
{
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
    {
        return true;
    }
    return false;
}

string reverseVowels(string s)
{
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
    {
        if (isVowel(s[i]) == false)
        {
            i++;
            continue;
        }
        if (isVowel(s[j]) == false)
        {
            j--;
            continue;
        }
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}
int main()
{
    struct input
    {
        string word1;
    };
    vector<input> input_list;
    input_list.push_back({"Uber Career Prep"});
    input_list.push_back({"xyz"});
    input_list.push_back({"flamingo"});
    vector<string> output_list = {"eber Ceraer PrUp", "xyz", "flominga"};
    for (int i = 0; i < input_list.size(); i++)
    {
        if (reverseVowels(input_list[i].word1) == output_list[i])
        {
            cout << "Passed!" << endl;
        }
    }
}

//This question took me 10 minutes 
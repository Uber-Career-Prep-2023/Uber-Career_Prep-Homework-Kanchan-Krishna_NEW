#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: Not sure - O(n^2)
Space Complexity: O(1)
Time it took me: 20 minutes
*/
// solve it with a stack or a vector using pop back function
// TC of substring is O(n)
// use two right pointers and compare both strings at the same time; skip # number of characters so if you have abcdef###xyz skip 3 hashtags so skip 3 chars for def

bool containsHashtag(string &s)
{
    for (auto character : s)
    {
        if (character == '#')
        {
            return true;
        }
    }
    return false;
}
string reduceString(string &s)
{ // modify the string directly
    while (containsHashtag(s))
    {
        string og_s = s;
        int idx_hashtag = s.find('#');
        string before = s.substr(0, idx_hashtag - 1);
        string after = og_s.substr(idx_hashtag + 1, og_s.length());
        s = before + after;
    }
    return s;
}
bool backspaceString(string &s1, string &s2)
{
    if (s1 == s2 || reduceString(s1) == reduceString(s2))
    {
        return true;
    }
    return false;
}
int main()
{
    /*string s1 = "abcde";
    string s2 = "abcde";*/
    /*string s1 = "Uber Career Prep";
    string s2 = "u#Uber Careee#r Prep";*/
    /*string s1 = "abcdef###xyz";
    string s2 = "abcw#xyz";*/
    string s1 = "abcdef###xyz";
    string s2 = "abcdefxyz###";
    if (backspaceString(s1, s2))
    {
        cout << "the resulting text is the same!";
    }
    else
    {
        cout << "the resulting text is not the same!";
    }
}
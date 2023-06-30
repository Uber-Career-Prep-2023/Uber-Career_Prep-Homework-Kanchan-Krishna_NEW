//Given a number, k, return an array of the first k binary numbers, represented as strings.

/*
Time Complexity: O(k)
Space Complexity: O(log k)
Time Taken: 30 min
Technique Used: Queue Technique 
*/

#include <bits/stdc++.h>
using namespace std; 

vector<string> FirstKBinaryNumbers(int k) {
    if (k == 0) {
        return {};
    }
    queue<string> numbers;
    numbers.push("1");
    vector<string> v;
    v.push_back("0");
    while (v.size() < k) {
        std::string s = numbers.front();
        v.push_back(s);
        numbers.pop();
        numbers.push(s + "0");
        numbers.push(s + "1");
    }
    return v;
}

void printOutput(vector<string>& v) {
    for (auto ele : v) {
        cout << ele << ", ";
    }
}

int main() {
    vector<string> v1 = FirstKBinaryNumbers(1);
    printOutput(v1);
    cout << "" << endl;
    vector<string> v2 = FirstKBinaryNumbers(5);
    printOutput(v2);
    cout << "" << endl;
    vector<string> v3 = FirstKBinaryNumbers(10);
    printOutput(v3);
    cout << "" << endl;
}
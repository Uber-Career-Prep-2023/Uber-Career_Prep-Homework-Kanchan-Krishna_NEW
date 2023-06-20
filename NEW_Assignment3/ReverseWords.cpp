//Given a string, return the string with the order of the space - separated words reversed

/*
Time Complexity: O(N)
Space Complexity: O(N)
Time Taken: 30 min
Technique Used: Stack reverse order
*/

#include <bits/stdc++.h>
using namespace std; 

string ReverseWords(std::string s) {
    stack<string> st;
    std::string reverse;
    std::string curr_word;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { //end of the word
            st.push(curr_word);
            curr_word = ""; //reset value
        } else if (i == s.size() - 1) {
            st.push(curr_word + s[i]);
        } else { //generate the word
            curr_word = curr_word + s[i];
        }
    }
    while (!st.empty()) {
        if (reverse == "") {
            reverse = st.top();
        } else {
            reverse = reverse + " " + st.top();
        }
        st.pop();
    }
    return reverse;
}

int main() {
    cout << ReverseWords("Uber Career Prep") << endl;
    cout << ReverseWords("Emma lives in Brooklyn, New York.");
}

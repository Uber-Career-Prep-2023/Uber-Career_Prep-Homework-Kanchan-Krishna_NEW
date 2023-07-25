#include <bits/stdc++.h>
using namespace std; 
// Implement a trie class, including the insert, search, and delete methods. Your class should adhere
// to the following API, adjusted appropriately for your language of choice.  

struct TrieNode {
    //assume vector only contains lowercase letters; otherwise size 52 
    vector<struct TrieNode*> children(26);
    bool validWord; 
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children.push_back(nullptr);
        }
        validWord = false; 
    }
};

class Trie {
    private: 
        struct TrieNode* root; 
    public:
        Trie() {
            root = new TrieNode(); 
        }
        void insert(string word) {
            TrieNode* curr = root; 
            int idx = 0; 
            for (int i = 0; i < word.length(); i++) {
                idx = word[i] - 'a';
                if (curr.children[idx] == nullptr) { //node does not exist
                    curr.children[idx] = new TrieNode(); 
                }
                curr = curr.children[idx];
            }
            curr->validWord = true; 
        }
        bool isValidWord(string word) {
            TrieNode* curr = root;
            bool is_valid = false; 
            int idx = 0; 
            for (int i = 0; i < word.length(); i++) {
                idx = word[i] - 'a';
                if (curr.children[idx]->validWord == true) {
                    is_valid = true;
                }
            }
            return is_valid;
        }
        void remove(string word) {

        }
        void printTrie() {
            TrieNode* curr = root; 
            for (int i = 0; i < curr.children.size(); i++) {

            }
        }
}

int main() {
    Trie t; 
    string word1 = "apple";
    string word2 = "ant";
    t.insert(word1);
    t.insert(word2);
}
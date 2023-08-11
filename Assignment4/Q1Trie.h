#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    vector<struct TrieNode*> children;
    bool validWord;
    TrieNode() : children(26, nullptr), validWord(false) {}
};

class Trie {
public:
    Trie();
    void insert(string word);
    bool isValidWord(string word);
    void remove(string word);
private:
    struct TrieNode* root;
    TrieNode* search(string& word);
    bool removeHelper(TrieNode* node, string& word, int depth);
    int countNodes(TrieNode *node);
};
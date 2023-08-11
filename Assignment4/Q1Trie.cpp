#include "Q1Trie.h"
using namespace std;

//constructor
Trie::Trie() {
    root = new TrieNode();
}

//TC: O(N) where N is the length of the word
void Trie::insert(string word) {
    TrieNode* curr = root;
    for (char letter : word) {
        int idx = letter - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = new TrieNode();
        }
        curr = curr->children[idx];
    }
    curr->validWord = true; //mark the end of a word
}

// TC: O(N) where N is the length of the word
bool Trie::isValidWord(string word) {
    TrieNode* curr = search(word);
    if (curr && curr->validWord) {
        return true;
    }
    return false;
}

// TC: O(N) where N is the length of the word
TrieNode* Trie::search(string &word) {
    TrieNode* curr = root;
    for (char letter : word) {
        int idx = letter - 'a';
        if (!curr->children[idx]) {
            return nullptr;
        }
        curr = curr->children[idx];
    }
    return curr;
}

// TC: O(N) where N is the length of the word
void Trie::remove(string word) {
    removeHelper(root, word, 0);
}

bool Trie::removeHelper(TrieNode *node, string &word, int depth) {
    if (!node) {
        return false;
    }
    if (distance == word.length()) {
        if (node->validWord) {
            node->validWord = false;
            return countChildren(node) == 0;
        }
        return false;
    }
    int idx = word[distance] - 'a';
    bool remove = removeHelper(node->children[idx], word, distance + 1);
    if (remove)
    {
        delete node->children[idx];
        node->children[idx] = nullptr; //avoid dangling pointer
    }
    return countNodes(node) == 0;
}

// TC: O(N) where N is the length of the children for the node
int Trie::countNodes(TrieNode* node) {
    int count = 0;
    for (TrieNode* child : node->children) {
        if (child) {
            count++;
        }
    }
    return count;
}

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("orange");
    cout << trie.isValidWord("apple") << endl;
    trie.remove("apple");
    trie.remove("orange");
}

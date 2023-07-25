#include <bits/stdc++.h>

// Implement a trie class, including the insert, search, and delete methods. Your class should adhere
// to the following API, adjusted appropriately for your language of choice.  

struct TrieNode {
   vector<struct TrieNode *> children; // a (resizable or fixed size) array of size 26
   bool validWord; // boolean to indicate if this node marks the end of a word
};

class Trie {
  struct TrieNode* root;

  void insert(string word); // adds a word to the trie
  bool isValidWord(string word); // returns a boolean indicating whether word is in the trie
  void remove(string word); // removes word, from the trie & deletes unused nodes
}

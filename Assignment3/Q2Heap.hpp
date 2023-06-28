#ifndef HEAP_HPP
#define HEAP_HPP
#include <bits/stdc++.h>

class MinHeap{
    /* 
        root node must be the smallest value in the "binary tree" & this must be recursively true across the tree 
        use a level order traversal to read in the heap
        root node will be first element in array 
        the value of each node will be >= its parent 
    */
    private:
        vector<int> v; // the underlying array
    public:
        int top();          // returns the min (top) element in the heap
        void insert(int x); // adds int x to the heap in the appropriate position
        void remove();      // removes the min (top) element in the heap
};

#endif
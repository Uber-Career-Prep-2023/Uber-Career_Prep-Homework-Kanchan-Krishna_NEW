#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC & SC: O(n) esp when you have a skewed tree like 4-3-2-1 to the left and recursive stack is going to store all these values
class Solution { // top down dfs
public:
    bool isValidBST(TreeNode *root) {
        return validHelper(root, nullptr, nullptr); //-inf and +inf
    }
    bool validHelper(TreeNode *root, TreeNode *low, TreeNode *high) {
        if (root == nullptr) {
            return true; // empty tree is a valid BST
        }
        if ((low != nullptr && low->val >= root->val) || (high != nullptr && high->val <= root->val)) {
            return false;
        }
        return valid(root->left, low, root) && valid(root->right, root, high);
        // moving on to left subtree: lower limit is same; high changes to root val
        // moving on to right subtree: high limit is same; low changes to prev root
    }
};
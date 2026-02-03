// NeetCode 150 - Trees
// Problem: Kth Smallest Element in a BST
// Difficulty: Medium
// Approach: Inorder Traversal (Sorted Order in BST)
// Time Complexity: O(n)
// Space Complexity: O(n)  // inorder result storage + recursion stack

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        return result[k - 1];
    }

    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};

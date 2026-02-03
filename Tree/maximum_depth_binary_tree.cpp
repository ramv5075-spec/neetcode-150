// NeetCode 150 - Trees
// Problem: Maximum Depth of Binary Tree
// Difficulty: Easy
// Approach: DFS (Recursive)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

#include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lheight = maxDepth(root->left);
        int rheight = maxDepth(root->right);
        return 1 + max(lheight, rheight);
    }
};

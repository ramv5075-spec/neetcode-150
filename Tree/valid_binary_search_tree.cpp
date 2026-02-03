// NeetCode 150 - Trees
// Problem: Validate Binary Search Tree
// Difficulty: Medium
// Approach: DFS (Min / Max Range Validation)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

#include <climits>
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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};

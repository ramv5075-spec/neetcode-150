// NeetCode 150 - Trees
// Problem: Balanced Binary Tree
// Difficulty: Easy
// Approach: DFS (Bottom-Up Height Check)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

#include <algorithm>
#include <cmath>
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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int lh = height(root->left);
        if (lh == -1) {
            return -1;
        }

        int rh = height(root->right);
        if (rh == -1) {
            return -1;
        }

        if (abs(lh - rh) > 1) {
            return -1;
        }

        return max(lh, rh) + 1;
    }
};

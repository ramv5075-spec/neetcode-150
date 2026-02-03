// NeetCode 150 - Trees
// Problem: Diameter of Binary Tree
// Difficulty: Easy
// Approach: DFS (Recursive, Height Calculation)
// Time Complexity: O(n^2)   // height() called for each node
// Space Complexity: O(h)    // h = height of the tree (recursion stack)

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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lheight = height(root->left);
        int rheight = height(root->right);
        return 1 + max(lheight, rheight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int currDiameter = height(root->left) + height(root->right);
        return max(currDiameter, max(leftDiameter, rightDiameter));
    }
};

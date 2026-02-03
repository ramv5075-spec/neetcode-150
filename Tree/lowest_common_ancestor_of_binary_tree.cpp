// NeetCode 150 - Trees
// Problem: Lowest Common Ancestor of a Binary Tree
// Difficulty: Medium
// Approach: DFS (Recursive)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
};

// NeetCode 150 - Trees
// Problem: Count Good Nodes in Binary Tree
// Difficulty: Medium
// Approach: DFS (Preorder with Running Maximum)
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
    int goodNodes(TreeNode* root) {
        int count = 0;
        if (root == nullptr) {
            return count;
        }
        countgoodNodes(root, count, root->val);
        return count;
    }

    void countgoodNodes(TreeNode* root, int& count, int maxVal) {
        if (root == nullptr) {
            return;
        }

        if (root->val >= maxVal) {
            count++;
            maxVal = root->val;
        }

        countgoodNodes(root->left, count, maxVal);
        countgoodNodes(root->right, count, maxVal);
    }
};

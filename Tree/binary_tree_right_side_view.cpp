// NeetCode 150 - Trees
// Problem: Binary Tree Right Side View
// Difficulty: Medium
// Approach: DFS (Right-first Preorder)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        recursion(root, 0, result);
        return result;
    }

    vector<int> recursion(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) {
            return result;
        }

        if (result.size() == level) {
            result.push_back(root->val);
        }

        recursion(root->right, level + 1, result);
        recursion(root->left, level + 1, result);

        return result;
    }
};

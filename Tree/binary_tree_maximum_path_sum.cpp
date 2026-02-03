// NeetCode 150 - Trees
// Problem: Binary Tree Maximum Path Sum
// Difficulty: Hard
// Approach: DFS (Postorder with Global Maximum)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

#include <climits>
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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }

    int maxPath(TreeNode* root, int &maxi) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = max(0, maxPath(root->left, maxi));
        int rightSum = max(0, maxPath(root->right, maxi));

        maxi = max(maxi, leftSum + rightSum + root->val);

        return max(leftSum, rightSum) + root->val;
    }
};

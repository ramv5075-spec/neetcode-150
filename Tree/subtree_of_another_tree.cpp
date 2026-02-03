// NeetCode 150 - Trees
// Problem: Subtree of Another Tree
// Difficulty: Easy
// Approach: DFS + Tree Comparison
// Time Complexity: O(n * m)   // n = nodes in root, m = nodes in subRoot
// Space Complexity: O(h)      // h = height of the tree

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
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        if (p->val == q->val &&
            isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right)) {
            return true;
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {
            return false;
        }

        if (isSameTree(root, subRoot)) {
            return true;
        }

        if (isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot)) {
            return true;
        }

        return false;
    }
};

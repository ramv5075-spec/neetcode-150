// NeetCode 150 - Trees
// Problem: Same Tree
// Difficulty: Easy
// Approach: DFS (Recursive Comparison)
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr) {
            return p == q;
        }
        return (p->val == q->val &&
                isSameTree(p->left, q->left) &&
                isSameTree(p->right, q->right));
    }
};

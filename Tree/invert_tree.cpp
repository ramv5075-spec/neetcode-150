// NeetCode 150 - Trees
// Problem: Invert Binary Tree
// Difficulty: Easy
// Approach: DFS (Recursive)
// Time Complexity: O(n)
// Space Complexity: O(h)  // h = height of the tree (recursion stack)

#include <cstddef>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }    
        invertTree(root->left);
        invertTree(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};

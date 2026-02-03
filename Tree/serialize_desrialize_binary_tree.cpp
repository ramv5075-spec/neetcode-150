// NeetCode 150 - Trees
// Problem: Serialize and Deserialize Binary Tree
// Difficulty: Hard
// Approach: DFS Preorder + Null Markers (#)
// Time Complexity: O(n)
// Space Complexity: O(n)  // output string + recursion stack

#include <string>
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

class Codec {
public:
    void serialize_dfs(TreeNode* root, string& s) {
        if (root == nullptr) {
            s.append(",#");
            return;
        }
        s.append("," + to_string(root->val));
        serialize_dfs(root->left, s);
        serialize_dfs(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serialize_dfs(root, s);
        return s;
    }

    TreeNode* deserialize_dfs(string& data, int& i) {
        i++;
        string num;

        while (i < (int)data.size() && data[i] != ',') {
            num += data[i];
            i++;
        }

        if (num == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(num));
        root->left = deserialize_dfs(data, i);
        root->right = deserialize_dfs(data, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        TreeNode* root = deserialize_dfs(data, i);
        return root;
    }
};

// NeetCode 150 - Tries
// Problem: Word Search II
// Difficulty: Hard
// Approach: Trie + DFS
// Time Complexity: O(m * n * 4^L)
// Space Complexity: O(N)

#include <vector>
#include <string>
using namespace std;

class Solution {
    struct Node {
        Node* links[26];
        bool flag = false;
        string word = "";

        bool containsKey(char ch) {
            return (links[ch - 'a'] != NULL);
        }

        Node* get(char ch) {
            return links[ch - 'a'];
        }

        void put(char ch, Node* node) {
            links[ch - 'a'] = node;
        }

        void setEnd(string& w) {
            flag = true;
            word = w;
        }

        bool isEnd() {
            return flag;
        }
    };

    Node* root;

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd(word);
    }

public:
    Solution() {
        root = new Node();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto str : words) {
            insert(str);
        }

        vector<string> result;
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || !node->containsKey(c)) return;

        node = node->get(c);
        if (node->isEnd()) {
            result.push_back(node->word);
            node->flag = false;
        }

        board[i][j] = '#';

        if (i > 0) dfs(board, i - 1, j, node, result);
        if (j > 0) dfs(board, i, j - 1, node, result);
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result);
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result);

        board[i][j] = c;
    }
};
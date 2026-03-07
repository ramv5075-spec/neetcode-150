// NeetCode 150 - Backtracking
// Problem: Word Search
// Difficulty: Medium
// Approach: Backtracking + DFS
// Time Complexity: O(m * n * 4^L)
// Space Complexity: O(m * n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }    
        return false;
    }

    bool isvalid(int i, int j, vector<vector<char>>& board, string word, int index, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return false;
        }
        if (visited[i][j] || word[index] != board[i][j]) {
            return false;
        }
        return true;
    }

    bool dfs(int i, int j, vector<vector<char>>& board, string word, int index, vector<vector<bool>>& visited) {
        if (index == word.length()) {
            return true;
        }
        if (!isvalid(i, j, board, word, index, visited)) {
            return false;
        }

        visited[i][j] = true;
        bool result = dfs(i + 1, j, board, word, index + 1, visited) ||
                      dfs(i - 1, j, board, word, index + 1, visited) ||
                      dfs(i, j + 1, board, word, index + 1, visited) ||
                      dfs(i, j - 1, board, word, index + 1, visited);
        visited[i][j] = false;

        return result;
    }
};
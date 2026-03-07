// NeetCode 150 - Backtracking
// Problem: N-Queens
// Difficulty: Hard
// Approach: Backtracking
// Time Complexity: O(n!)
// Space Complexity: O(n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
        backtrack(result, board, leftRow, lowerDiagonal, upperDiagonal, 0, n);
        return result;
    }

    void backtrack(vector<vector<string>>& result, vector<string>& board, vector<int>& leftRow,
                   vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int col, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                backtrack(result, board, leftRow, lowerDiagonal, upperDiagonal, col + 1, n);

                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
};
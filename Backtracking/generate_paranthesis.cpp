// NeetCode 150 - Backtracking
// Problem: Generate Parentheses
// Difficulty: Medium
// Approach: Backtracking
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, n, 0, 0, "");
        return result;
    }

    void backtrack(vector<string>& result, int n, int open, int close, string curr_str) {
        if (curr_str.size() == n * 2) {
            result.push_back(curr_str);
            return;
        }

        if (open < n) {
            backtrack(result, n, open + 1, close, curr_str + "(");
        }

        if (close < open) {
            backtrack(result, n, open, close + 1, curr_str + ")");
        }
    }
};
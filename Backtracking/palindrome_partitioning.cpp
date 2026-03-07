// NeetCode 150 - Backtracking
// Problem: Palindrome Partitioning
// Difficulty: Medium
// Approach: Backtracking
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        backtrack(result, temp, s, 0);
        return result; 
    }

    void backtrack(vector<vector<string>>& result, vector<string>& temp, string s, int index) {
        if (index == s.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (ispalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i - index + 1));
                backtrack(result, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }

    bool ispalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};
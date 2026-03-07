// NeetCode 150 - Backtracking
// Problem: Letter Combinations of a Phone Number
// Difficulty: Medium
// Approach: Backtracking
// Time Complexity: O(4^n)
// Space Complexity: O(n)

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string digits, unordered_map<char, string>& mp, string str, int index) {
        if (str.length() == digits.length()) {
            result.push_back(str);
            return;
        }

        string opt = mp[digits[index]];
        for (auto s : opt) {
            str.push_back(s);
            backtrack(result, digits, mp, str, index + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }

        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(result, digits, mp, "", 0);
        return result;
    }
};
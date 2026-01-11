// NeetCode 150 - Sliding Window
// Problem: Longest Repeating Character Replacement
// Difficulty: Medium
// Approach: Sliding Window with Frequency Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, res = 0, maxFreq = 0;

        for (int r = 0; r < s.length(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            if ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};

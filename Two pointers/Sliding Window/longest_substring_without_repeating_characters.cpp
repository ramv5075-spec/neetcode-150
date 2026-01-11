// NeetCode 150 - Sliding Window
// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Approach: Sliding Window + Frequency Array
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> chars(128);
        int left = 0, right = 0, result = 0;

        while (right < s.length()) {
            char r = s[right];
            chars[r]++;

            while (chars[r] > 1) {
                char l = s[left];
                chars[l]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};

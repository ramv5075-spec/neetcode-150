// NeetCode 150 - Sliding Window
// Problem: Minimum Window Substring
// Difficulty: Hard
// Approach: Sliding Window + Frequency Map
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) {
            return "";
        }

        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int i = 0, j = 0;
        int requiredCount = t.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;

        while (j < s.length()) {
            if (mp[s[j]] > 0) {
                requiredCount--;
            }
            mp[s[j]]--;

            while (requiredCount == 0) {
                int currWindowSize = j - i + 1;
                if (minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    requiredCount++;
                }
                i++;
            }
            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};

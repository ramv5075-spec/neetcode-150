// NeetCode 150 - Sliding Window
// Problem: Permutation in String
// Difficulty: Medium
// Approach: Sliding Window + Frequency Arrays
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26, 0);
        vector<int> s2hash(26, 0);

        if (s1.length() > s2.length()) {
            return false;
        }

        int l = 0, r = 0;

        while (r < s1.length()) {
            s1hash[s1[r] - 'a'] += 1;
            s2hash[s2[r] - 'a'] += 1;
            r += 1;
        }
        r -= 1;

        while (r < s2.length()) {
            if (s1hash == s2hash)
                return true;

            r += 1;
            if (r != s2.length()) {
                s2hash[s2[r] - 'a'] += 1;
            }

            s2hash[s2[l] - 'a'] -= 1;
            l += 1;
        }
        return false;
    }
};

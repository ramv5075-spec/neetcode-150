// NeetCode 150 - Backtracking
// Problem: Permutations
// Difficulty: Medium
// Approach: Backtracking (Swap Method)
// Time Complexity: O(n * n!)
// Space Complexity: O(n)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, int i, int n) {
        if (i == n) {
            result.push_back(nums);
            return;
        }

        for (int j = i; j <= n; j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1, n);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size() - 1);
        return result;    
    }
};
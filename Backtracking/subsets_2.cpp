// NeetCode 150 - Backtracking
// Problem: Subsets II
// Difficulty: Medium
// Approach: Backtracking with duplicate skipping
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(result, temp, nums, 0);
        return result;  
    }

    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& nums, int index) {
        result.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            if (i != index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(result, temp, nums, i + 1);
            temp.pop_back();
        }
    }
};
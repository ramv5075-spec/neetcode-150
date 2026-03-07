// NeetCode 150 - Backtracking
// Problem: Combination Sum II
// Difficulty: Medium
// Approach: Backtracking
// Time Complexity: O(2^n)
// Space Complexity: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result, temp, candidates, target, 0);
        return result;    
    }

    void backtrack(vector<vector<int>>& result, vector<int>& temp, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            backtrack(result, temp, candidates, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
};
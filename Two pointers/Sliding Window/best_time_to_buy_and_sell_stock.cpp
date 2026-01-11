// NeetCode 150 - Sliding Window
// Problem: Best Time to Buy and Sell Stock
// Difficulty: Easy
// Approach: Single Pass with Minimum Price Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, mini = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int cost = prices[i] - mini;
            profit = max(cost, profit);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

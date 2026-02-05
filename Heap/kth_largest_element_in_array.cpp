// NeetCode 150 - Heap / Priority Queue
// Problem: Kth Largest Element in an Array
// Difficulty: Medium
// Approach: Min Heap of size K
// Time Complexity: O(n log k)
// Space Complexity: O(k)

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int it : nums) {
            pq.push(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};

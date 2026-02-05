// NeetCode 150 - Heap / Priority Queue
// Problem: K Closest Points to Origin
// Difficulty: Medium
// Approach: Max Heap of size K
// Time Complexity: O(n log k)
// Space Complexity: O(k)

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap storing (distance, (x, y))
        priority_queue<pair<int, pair<int, int>>> pq;

        for (auto& it : points) {
            int distance = it[0] * it[0] + it[1] * it[1];
            pq.push({distance, {it[0], it[1]}});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back({
                pq.top().second.first,
                pq.top().second.second
            });
            pq.pop();
        }

        return result;
    }
};

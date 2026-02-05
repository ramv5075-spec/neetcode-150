// NeetCode 150 - Heap / Priority Queue
// Problem: Last Stone Weight
// Difficulty: Easy
// Approach: Max Heap (Priority Queue)
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int it : stones) {
            pq.push(it);
        }

        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            if (first != second) {
                pq.push(first - second);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};

// NeetCode 150 - Heap / Priority Queue
// Problem: Kth Largest Element in a Stream
// Difficulty: Easy
// Approach: Min Heap of size K
// Time Complexity: O(log k) per add operation
// Space Complexity: O(k)

#include <queue>
#include <vector>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int it : nums) {
            pq.push(it);
            if (pq.size() > size) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
};

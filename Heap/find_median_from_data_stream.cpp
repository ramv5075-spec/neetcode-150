// NeetCode 150 - Heap / Priority Queue
// Problem: Find Median from Data Stream
// Difficulty: Hard
// Approach: Two Heaps (Max Heap + Min Heap)
// Time Complexity:
//   addNum: O(log n)
//   findMedian: O(1)
// Space Complexity: O(n)

#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    // Max heap for the smaller half
    priority_queue<int> maxHeap;
    // Min heap for the larger half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}

    void addNum(int num) {
        // Always push to maxHeap first
        maxHeap.push(num);
        // Balance: move largest of smaller half to minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Ensure maxHeap has equal or one more element than minHeap
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

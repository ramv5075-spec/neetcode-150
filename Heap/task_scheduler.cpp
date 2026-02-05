// NeetCode 150 - Heap / Priority Queue
// Problem: Task Scheduler
// Difficulty: Medium
// Approach: Greedy + Max Heap
// Time Complexity: O(n log 26) ≈ O(n)
// Space Complexity: O(1)

#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (char c : tasks) {
            freq[c]++;
        }

        priority_queue<int> pq;
        for (auto& it : freq) {
            pq.push(it.second);
        }

        int result = 0;

        while (!pq.empty()) {
            int time = 0;
            vector<int> temp;

            // Execute up to (n + 1) tasks per cycle
            for (int i = 0; i < n + 1; i++) {
                if (!pq.empty()) {
                    int cnt = pq.top(); pq.pop();
                    if (--cnt > 0) {
                        temp.push_back(cnt);
                    }
                    time++;
                }
            }

            // Push remaining tasks back into heap
            for (int cnt : temp) {
                pq.push(cnt);
            }

            // If heap empty, add actual time used; otherwise full cycle
            result += pq.empty() ? time : n + 1;
        }

        return result;
    }
};

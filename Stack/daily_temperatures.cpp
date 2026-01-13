// NeetCode 150 - Stack
// Problem: Daily Temperatures
// Difficulty: Medium
// Approach: Monotonic Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<int> st;
        for(int i=temperatures.size()-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                result[i]=st.top()-i;
            }
            st.push(i);
        }  
        return result;
    }
};

// NeetCode 150 - Stack
// Problem: Min Stack
// Difficulty: Medium
// Approach: Two Stacks
// Time Complexity: O(1) for all operations
// Space Complexity: O(n)

#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> minstack;  

    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty() || val<=minstack.top()){
            minstack.push(val);
        }
    }
    
    void pop() {
        int val=st.top();
        st.pop();
        if(val==minstack.top()){
            minstack.pop();
        }   
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

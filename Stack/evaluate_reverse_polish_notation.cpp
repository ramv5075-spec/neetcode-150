// NeetCode 150 - Stack
// Problem: Evaluate Reverse Polish Notation
// Difficulty: Medium
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto c:tokens){
            if(c=="+") {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val1+val2);
            } else if(c=="-") {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val2-val1);
            }
            else if(c=="*") {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val2*val1);
            } else if(c=="/") {
                int val1=st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                st.push(val2/val1);
            } else {
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};

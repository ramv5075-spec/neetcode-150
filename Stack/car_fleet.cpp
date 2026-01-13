// NeetCode 150 - Stack
// Problem: Car Fleet
// Difficulty: Medium
// Approach: Stack + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> car(position.size());
        for(int i=0;i<position.size();i++){
            car[i]=make_pair(position[i],(double)(target-position[i])/speed[i]);
        }
        stack<double> st;
        sort(car.begin(),car.end());
        for(int i=position.size()-1;i>=0;i--){
            if(st.empty() || st.top()<car[i].second){
                st.push(car[i].second);
            }
        }
        return st.size();
    }
};

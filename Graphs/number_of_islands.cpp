// NeetCode 150 - Graph / BFS
// Problem: Number of Islands
// Difficulty: Medium
// Approach: Use BFS to visit all connected land cells ('1').
//           Every time we find an unvisited land cell, it represents a new island.
// Time Complexity: O(n * m)
//   n = number of rows, m = number of columns
//   Each cell is visited at most once.
// Space Complexity: O(n * m)
//   visited matrix + queue in worst case

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& visited,vector<vector<char>>& grid,int row,int col){
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        visited[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                    int nRow=row+directions[i][0];
                    int nCol=col+directions[i][1];
                    if(nRow>=0 && nRow<n && nCol>=0 && nCol<m &&
                    grid[nRow][nCol]=='1' && !visited[nRow][nCol]){
                        visited[nRow][nCol]=1;
                        q.push({nRow,nCol});
                    }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col]=='1'){
                    count++; 
                    bfs(visited,grid,row,col);
                }
            }
        }  
        return count;
    }
};
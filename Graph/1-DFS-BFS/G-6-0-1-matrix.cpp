https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

class Solution {
    public:
      // Function to find distance of nearest 1 in the grid for each cell.
      vector<vector<int>> bfs(vector<vector<int>>& grid, 
              vector<vector<int>>& vis, vector<vector<int>>& ans){
              
          queue<pair<pair<int,int>, int>>q;
          int n= grid.size();
          int m= grid[0].size();
          
          for(int i=0;i<n; i++){
              for(int j=0; j<m; j++){
                  if(grid[i][j] == 1){ // in leetcode we check for 0 so put 0 there
                      q.push({{i,j},0});
                      vis[i][j]= 1;
                  }
              }
          }
          
          int drow[] = {-1, 0, 1, 0};
          int dcol[]= {0, 1, 0, -1};
          
          while(!q.empty()){
              int row= q.front().first.first;
              int col= q.front().first.second;
              int d= q.front().second;
              q.pop();
              ans[row][col]= d;
              
              for(int k=0; k<4; k++){
                  int nrow= row+drow[k];
                  int ncol= col+dcol[k];
                  
                  if(nrow >= 0 and nrow <n and ncol >= 0 and ncol < m and !vis[nrow][ncol]){
                      q.push({{nrow, ncol}, d+1});
                      vis[nrow][ncol]=1;
                  }
              }
          }
          return ans;
      }
      
      vector<vector<int>> nearest(vector<vector<int>>& grid) {
          int n= grid.size();
          int m= grid[0].size();
          vector<vector<int>> vis(n ,vector<int>(m ,0));
          vector<vector<int>> ans(n ,vector<int>(m ,0));
          
          return bfs(grid, vis, ans);
          
      }
  };
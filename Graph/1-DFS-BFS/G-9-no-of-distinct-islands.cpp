// refer- https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

// here we are using concept of the same graph orientataion
// suppose (0,0) -- (0,1)  here (0,0) is base we subtract base from all other
//           |
//         (1,0)
class Solution {
    public:
      vector<pair<int,int>> dfs(int i, int j, int r0, int c0, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &temp){
          vis[i][j]= 1;
          temp.push_back({i-r0, j-c0}); //here r0, c0 is base
          
          int n= grid.size();
          int m= grid[0].size();
          
          int drow[]= {-1, 0, 1, 0};
          int dcol[]= {0, 1, 0, -1};
          
          for(int k=0; k<4; k++){
              int nrow= i+drow[k];
              int ncol= j+dcol[k];
              
              if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] and !vis[nrow][ncol]){
                  // temp.push_back({basei-nrow, basej-ncol});
                  vis[nrow][ncol]= 1;
                  dfs(nrow, ncol, r0, c0, grid, vis, temp);
              }
          }
          return temp;
      }
      int countDistinctIslands(vector<vector<int>>& grid) {
          int n= grid.size();
          int m= grid[0].size();
          
          vector<vector<int>> vis(n, vector<int>(m, 0));
          
          set<vector<pair<int,int>>> s;
          
          for(int i=0; i<n; i++){
              for(int j=0; j<m; j++){
                  if(!vis[i][j] and grid[i][j] == 1){
                      vector<pair<int,int>> temp;
                      dfs(i, j, i, j, grid, vis, temp);
                      s.insert(temp);
                  }
              }
          }
          return s.size();
          
      }
  };
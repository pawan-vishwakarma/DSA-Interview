class Solution {
    public: 
    // refer- https://leetcode.com/problems/number-of-enclaves/
        void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis){
            vis[i][j]= 1;
            grid[i][j]= 0;
                    // cout<<i<<' '<<j<<endl;
    
            int n= grid.size();
            int m= grid[0].size();
    
            int drow[]= {-1, 0, 1, 0};
            int dcol[]= {0, 1, 0, -1};
    
            for(int k=0; k<4; k++){
                int nrow= i+drow[k];
                int ncol= j+dcol[k];
    
                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol] == 1){
                    // cout<<nrow<<' '<<ncol<<endl;
                    dfs(nrow, ncol, grid, vis);
                }
            }
        }
        int numEnclaves(vector<vector<int>>& grid) {
            int n= grid.size();
            int m= grid[0].size();
    
            vector<vector<int>>vis(n, vector<int>(m, 0));
    
            // first and last col
            for(int i=0; i<n;i++){
               if(grid[i][0] == 1){
                    dfs(i, 0, grid, vis);
               }
    
               if(grid[i][m-1] == 1){
                    dfs(i, m-1, grid, vis);
               }
            }
    
            // first and last row
            for(int i=0; i<m;i++){
               if(grid[0][i] == 1){
                    dfs(0, i, grid, vis);
               }
    
               if(grid[n-1][i] == 1){
                    dfs(n-1, i, grid, vis);
               }
            }
    
            int cnt=0;
            // count left 1's
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1) cnt++;
                }
            }
            
            return cnt;
        }
    };
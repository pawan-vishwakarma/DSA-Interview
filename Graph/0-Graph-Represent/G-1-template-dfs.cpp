
//dfs on grid with 4 direction 

void dfs(int i, int j, vector<vector<int>> grid, vector<vector<int>> vis){
    vis[i][j]= 1;

    // 4 direction 
    for(int i=0; i<4; i++){
        int nrow= i+delrow[i];
        int ncol= j+delcol[i];

        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol]){
            dfs(nrow, ncol, grid, vis);
        }
    }
}
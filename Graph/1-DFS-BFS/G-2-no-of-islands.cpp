class Solution {
    public:
    // refer- https://leetcode.com/problems/number-of-islands/
        void bfs(int i, int j, vector<vector<char>> & grid, vector<vector<int>> & vis){
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j]= 1;
            int n= grid.size();
            int m= grid[0].size();
    
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
    
            while(!q.empty()){
                int row= q.front().first;
                int col= q.front().second;
                q.pop();
    
                // all eight directiosn
                for(int k= 0; k<4; k++){
                    
                    int nrow= row+dx[k];
                    int ncol= col+dy[k];
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and !vis[nrow][ncol] and grid[nrow][ncol]== '1'){
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                        cout<<nrow<<" "<<ncol<<", ";
                    }
                    
                }
            }
    
        }
        int numIslands(vector<vector<char>>& grid) {
            int n= grid.size();
            int m= grid[0].size();
            vector<vector<int>>vis(n, vector<int>(m, 0));
            int cnt=0;
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] and grid[i][j] == '1'){
                        cnt++;
                        bfs(i, j, grid, vis);
                    }
                }
            }
            return cnt;
        }
    };
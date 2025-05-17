class Solution {
    public:
    // refer- https://leetcode.com/problems/rotting-oranges/
        int orangesRotting(vector<vector<int>>& grid) {
            int n= grid.size();
            int m= grid[0].size();
    
            int vis[11][11];
    
            queue<pair<pair<int,int>, int>>q;
            int frshcnt=0 ;
    
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 2){
                        q.push({{i,j},0});
                        vis[i][j]= 2;
                    }
                    else if(grid[i][j] == 1){
                        frshcnt++;
                    }
                    else{
                        vis[i][j]= 0;
                    }
                }
            }
            if(frshcnt == 0) return 0;
    
            int drow[]= {-1, 0, 1, 0};
            int dcol[]= {0, 1, 0, -1};  
            int tmax= INT_MIN;
    
            while(!q.empty()){
                int row= q.front().first.first;
                int col= q.front().first.second;
                int t= q.front().second;
                q.pop();
                tmax= max(tmax, t);
    
                for(int i=0; i<4; i++){
                    int nrow= row+drow[i];
                    int ncol= col+dcol[i];
    
    
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m 
                        and grid[nrow][ncol] == 1 and vis[nrow][ncol] == 0){
                            vis[nrow][ncol]= 1;
                            q.push({{nrow, ncol},t+1});
                            frshcnt--;
                        }
                }
            }
    
            return frshcnt == 0? tmax : -1;
        }
    };
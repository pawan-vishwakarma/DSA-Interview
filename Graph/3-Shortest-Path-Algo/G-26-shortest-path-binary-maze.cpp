class Solution {
    public:
    // refer- https://leetcode.com/problems/shortest-path-in-binary-matrix/
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            // Classic Dijkstra's Algo
    
            // check if start is valid
            if(grid[0][0] == 1) return -1;
            // initialse queue no need of PQ beacuse the grid will be in incremental at any point
            queue<pair<int,int>> q;
            q.push({0,0});
    
            int n= grid.size();
            int m= grid[0].size();
    
            // act as a vsiited array
            vector<vector<int>> dist(n, vector<int>(m, 1e9));
            dist[0][0]= 1;
    
            while(!q.empty()){
                int row= q.front().first;
                int col= q.front().second;
                q.pop();
    
                // if [n,m] visited
                if(row == n-1 and col == m-1) return dist[n-1][m-1];
    
                // checking out all 8-directions
                for(int i=-1; i<2; i++){
                    for(int j=-1; j<2; j++){
                        int nrow= row+i;
                        int ncol= col+j;
    
                        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == 0){
                            // here replacing the old values with mini values
                            if(dist[nrow][ncol] > dist[row][col]+1){
                                dist[nrow][ncol]= dist[row][col]+1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
            //final check if reached then return ans otherwise -1
            return dist[n-1][m-1] == 1e9 ? -1: dist[n-1][m-1];
        }
    };
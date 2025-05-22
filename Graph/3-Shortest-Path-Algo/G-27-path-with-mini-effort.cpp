class Solution {
    public:
    // refer- https://leetcode.com/problems/path-with-minimum-effort/
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n= heights.size();
            int m= heights[0].size();
    
            priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
            vector<vector<int>> dist(n, vector<int>(m, 1e9));
    
            dist[0][0]= 0;
            pq.push({0, {0, 0}});
            int drow[]= {-1, 0, 1, 0};
            int dcol[]= {0, 1, 0, -1};
    
            while(!pq.empty()){
                int row= pq.top().second.first;
                int col= pq.top().second.second;
                int mineffort= pq.top().first;
    
                pq.pop();
    
                for(int i=0; i<4; i++){
                    int nrow= row+drow[i];
                    int ncol= col+dcol[i];
    
                    if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m ){
                        // absdiff b/w cells
                        int absdiff= abs(heights[row][col]- heights[nrow][ncol]);
                        // max of abs diff
                        int maxabs= max(mineffort, absdiff);
    
                        if(dist[nrow][ncol] > maxabs){
                            dist[nrow][ncol]= maxabs;
                            pq.push({maxabs, {nrow, ncol}});
                        }
                    }
                }
    
            }
            return dist[n-1][m-1];
    
        }
    };
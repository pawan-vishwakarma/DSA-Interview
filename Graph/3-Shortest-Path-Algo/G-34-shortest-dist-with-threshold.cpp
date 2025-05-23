class Solution {
    public:
    // refer- https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
        int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
            // generate matrix from edges
            vector<vector<int>> matrix(n, vector<int>(n, 1e8));
    
            // marking diagonal as 0 
            for(int i=0; i<n; i++){
                matrix[i][i]= 0;
            }
    
            // making undriected to directed
            for(auto it: edges){
                int u= it[0];
                int v= it[1];
                int wt= it[2];
    
                matrix[u][v]= wt;
                matrix[v][u]= wt;
            }
    
            // first we use floyd warshall algo to generate matrix with shortest dist b/w them
            for(int via= 0; via<n; via++){
                for(int i=0; i<n; i++){
                    for(int j=0; j<n; j++){
                        if(matrix[i][via] == 1e8 || matrix[via][j] == 1e8)continue;
                        matrix[i][j]= min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                    }
                }
            }
    
            // now the matrix represent the minimu dist b/w edges
            int mincnt= n, ans=-1, cnt=0;
            for(int i=0; i<n; i++){
                // keeping count of dist <= threshold for each row
                cnt= 0;
                for(int j=0; j<n; j++){
                    if(matrix[i][j] <= distanceThreshold){
                        cnt++;
                    }
                }
                // we need minimum cnt so checking and assigning ans with row
                if(mincnt > cnt){
                    mincnt= cnt;
                    ans = i;
                }
                // here if any two row have minimum cnt then bigger row is given preference
                else if(mincnt == cnt){
                    ans= i;
                }
            }
            return ans;
        }
    };
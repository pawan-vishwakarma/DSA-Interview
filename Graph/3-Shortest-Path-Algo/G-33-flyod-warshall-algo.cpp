// User function template for C++

class Solution {
    // refer- https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        
        int n= dist.size();
        
        // passing matrix with via from 0->n
        for(int via=0; via<n; via++){
            // updating matrix with every via
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via] == 1e8 || dist[via][j] == 1e8) continue;
                    // adding here will overflow 1e8+1e8 therfore use continue
                    dist[i][j]= min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
        return;
    }
};
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

        // for detetcting -ve cycle
        // why this working because from 0->0 cost must be 0 similar from 1->1 cost must be zero
        // if for any edge cost is less than zero it means there exist -ve cycle
        for(int i=0; i<n; i++){
            if(dist[i][i] < 0) {
                cout<<"Negative cycle exist";
            }
        }
        return;
    }
};
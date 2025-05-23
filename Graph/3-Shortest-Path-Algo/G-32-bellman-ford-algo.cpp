// User function Template for C++

class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
          
          // define dist array
          vector<int> dist(V, 1e8);
          
          // define src dist as 0
          dist[src]= 0;
          
          // do v-1 treaversal
          // V*E TC 
          for(int i=0; i<V-1; i++){
              for(auto it: edges){
                  int u= it[0];
                  int v= it[1];
                  int wt= it[2];
                  // doing relaxation
                  if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                      dist[v]= dist[u]+wt;
                  }
              }
          }
          
          // doing nth relaxation to check -ve cycle
          for(auto it: edges){
              int u= it[0];
              int v= it[1];
              int wt= it[2];
              // doing relaxation
              if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                  return {-1} ;
              }
          }
          return dist;
      }
  };
  
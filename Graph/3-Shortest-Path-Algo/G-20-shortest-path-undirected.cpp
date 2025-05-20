class Solution {
    public:
      // refer- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          
          queue<pair<int, int>> q;
          q.push({src, 0});
          
          int n= adj.size();
          vector<int> dist(n, 1e9);
          dist[src]= 0;
          
          while(!q.empty()){
              auto it= q.front();
              
              int neighNode= it.first;
              int neighDist= it.second;
              q.pop();
              
              for(auto it: adj[neighNode]){
                  
                  if(neighDist+1 < dist[it]){
                      dist[it]= neighDist+1;
                      q.push({it, dist[it]});
                  }
                  
              }
              
          }
          
          for(int i=0; i<n; i++){
              if(dist[i] == 1e9) dist[i]= -1;
          }
          return dist;
          
      }
  };
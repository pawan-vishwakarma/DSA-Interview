class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
          // priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
          
          set<pair<int,int>>s;
          
          vector<int> dist(V, 1e9);
          
          vector<pair<int,int>> adj[V];
          for(auto edge: edges){
              int u= edge[0];
              int v= edge[1];
              int wt= edge[2];
              
              adj[u].push_back({v,wt});
              adj[v].push_back({u,wt});
          }
          
          s.insert({0, src});
          dist[src]= 0;;
          
          while(!s.empty()){
              auto it= *(s.begin());
              int wt= it.first;
              int node= it.second;
              s.erase(it);
              
              for(auto it: adj[node]){
                  int neighNode= it.first;
                  int neighDist= it.second;
                  
                  if(wt+neighDist < dist[neighNode]){
                      // if already exist in set with higher number then remove that
                      if(dist[neighNode] != 1e9){
                          s.erase({dist[neighNode], neighNode});
                      }
                      
                      dist[neighNode]= wt+neighDist;
                      s.insert({dist[neighNode], neighNode});
                  }
              }
          }
          return dist;
      }
  };
class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
          priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
          vector<int> dist(V, 1e9);
          
          vector<pair<int,int>> adj[V];
          for(auto edge: edges){
              int u= edge[0];
              int v= edge[1];
              int wt= edge[2];
              
              adj[u].push_back({v,wt});
              adj[v].push_back({u,wt});
          }
          
          pq.push({0, src});
          dist[src]= 0;;
          
          while(!pq.empty()){
              auto it= pq.top();
              int wt= it.first;
              int node= it.second;
              pq.pop();
              
              for(auto it: adj[node]){
                  int neighNode= it.first;
                  int neighDist= it.second;
                  
                  if(wt+neighDist < dist[neighNode]){
                      dist[neighNode]= wt+neighDist;
                      pq.push({dist[neighNode], neighNode});
                  }
              }
          }
          return dist;
      }
  };
class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
      vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
          vector<pair<int,int>> adj[n+1];
          for(auto& edge: edges){
              int u = edge[0];
              int v = edge[1];
              int wt = edge[2];
              adj[u].push_back({v, wt});
              adj[v].push_back({u, wt});
          }
  
          vector<int> dist(n+1, 1e9);
          vector<int> parent(n+1);
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  
          for(int i = 1; i <= n; i++) parent[i] = i;
          dist[1] = 0;
          pq.push({0, 1});
  
          while(!pq.empty()){
              auto top = pq.top(); pq.pop();
              int d = top.first;
              int u = top.second;
  
              for(auto it : adj[u]){
                  int v = it.first;
                  int wt = it.second;
                  if(d + wt < dist[v]){
                      dist[v] = d + wt;
                      pq.push({dist[v], v});
                      parent[v] = u;
                  }
              }
          }
  
          if(dist[n] == 1e9) return {-1}; // No path
  
          vector<int> path;
          for(int node = n; node != parent[node]; node = parent[node]){
              path.push_back(node);
          }
          path.push_back(1);
          path.push_back(dist[n]);
          reverse(path.begin(), path.end());
  
          return path;
      }
  };
  
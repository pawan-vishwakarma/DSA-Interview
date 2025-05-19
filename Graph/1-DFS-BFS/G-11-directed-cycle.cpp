
// refer- https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
    public:
      bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> adjL[]){
          vis[node]=1;
          path[node]=1;
          
          for(auto it: adjL[node]){
              if(!vis[it]){
                  if(dfs(it, vis, path, adjL)) return true;
              }
              else if(path[it]){
                  return true;
              }
          }
          
          path[node]= 0;
          return false;
      }
      bool isCyclic(int V, vector<vector<int>> &edges) {
          
          vector<int>adjl[V];
          
          for(auto edge: edges){
              int u= edge[0];
              int v= edge[1];
              
              adjl[u].push_back(v);
          }
          
          vector<int> path(V, 0);
          vector<int> vis(V, 0);
          
          for(int i=0; i<V; i++){
              if(!vis[i]){
                  if(dfs(i, vis, path, adjl)) return true;
              }
          }
          return false;
          
      }
  };
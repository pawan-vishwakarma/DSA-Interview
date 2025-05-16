// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1

class Solution {
    public:
        // template bfs call
      vector<int> bfs(int node, vector<int> adjL[], vector<int> &vis){
          queue<int> q;
          q.push(node);
          vector<int> ans;
          vis[node]=1;
          
          while(!q.empty()){
              int neigh= q.front();
              q.pop();
              ans.push_back(neigh);
              for(int it: adjL[neigh]){
                  if(!vis[it]){
                      q.push(it);
                      vis[it]=1;
                  }
              }
          }
          sort(ans.begin(), ans.end());
          return ans;
      }
      
      vector<vector<int>> getComponents(int v, vector<vector<int>>& edges) {

          //  converting 2D array to adjL
          
          vector<int> adjL[v];
          
          for(auto it: edges){
              int u= it[0];
              int v= it[1];
              adjL[u].push_back(v);
              adjL[v].push_back(u);
          }
          
          vector<int> vis(v, 0);
          vector<vector<int>> ans;
          
          for(int i=0; i<v; i++){
              if(!vis[i]){
                  ans.push_back(bfs(i, adjL, vis));
              }
          }
          return ans;
          
      }
  };
  
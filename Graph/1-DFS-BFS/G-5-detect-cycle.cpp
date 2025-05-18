class Solution {
    // refer- https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
    // TC- O(N+2E)
    public:
      // Function to detect cycle in an undirected graph.
      bool bfs(int src, vector<vector<int>>& adj, vector<int> &visit){
          
          queue<pair<int,int>> q;
          q.push({src,-1});
          visit[src] = 1;
          
          while(!q.empty()){
              int front = q.front().first;
              int parent = q.front().second;
              q.pop();
              for(auto neigh:adj[front]){
                  if(!visit[neigh]){
                      visit[neigh] = 1;
                      q.push({neigh,front});
                  }
                  else if(parent != neigh){
                      return true;
                  }
              }
          }
          return false;
      }
      bool isCycle(vector<vector<int>>& adj) {
          
          int n =adj.size();
          
          if(n < 3) return false;
          
          vector<int> visit(n,0);
          vector<int> adjL[n];
          
          // for(int i=0;i<n;i++){
          //     for(int j=0;j<m;j++){
          //         adjL[i].push_back()
          //     }
          // }
          for(int i=0;i<n;i++){
              if(!visit[i]){
                 if(bfs(i,adj,visit)) return true;
              }
          }
          return false;
      }
  };


  // using dfs
  int vis[1000];
  vector<int> adjL[1000]; // alrady defined

  bool dfs(int node, int parent){
    vis[node]=1;
    for(auto it : adjL[node]){
        if(!vis[it]){
            if(dfs(it, node)) return true;
        }
        else if( it != parent){
            return true; // cycle exist
        }
    }
    return false;
  }
  // TC- O(N+2E)+O(N)
  // SC- O(N)+O(N)
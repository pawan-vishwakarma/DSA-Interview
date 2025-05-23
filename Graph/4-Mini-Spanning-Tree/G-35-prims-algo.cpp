class Solution {
    public:
    // refer- https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
    
      // Function to find sum of weights of edges of the Minimum Spanning Tree.
      int spanningTree(int V, vector<vector<int>> adj[]) {
          
          // min priority queue --. {wt, node, parent}
          priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, 
                          greater<pair<int, pair<int,int>>>> pq;
                          
          pq.push({0, {0, -1}}); // first node therefor parent =-1
          
          // visited array
          vector<int> vis(V+1, 0);
          
          // sum of edges
          int sum= 0;
          
          while(!pq.empty()){
              auto it= pq.top();
              
              int uwt= it.first;
              int u= it.second.first;
              int parent= it.second.second;
              pq.pop();
              
              if(vis[u]) continue;
              
              // here we will add it to mst
              vis[u]= 1;
              sum += uwt; 
              
              for(auto it: adj[u]){
                  int v= it[0];
                  int vwt= it[1];
                  // just put in pq
                  if(!vis[v]){
                      pq.push({vwt, {v, u}});
                  }
              }
          }
          return sum;
          
      }
  };
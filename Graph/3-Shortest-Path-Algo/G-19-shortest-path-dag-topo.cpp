class Solution {
    public:
    
    // refer- https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
    
      // void shortestDist(vector<pair<int,int>> adj[] , int node, vector<int> &dist){
  
      //     for(auto it : adj[node]){
      //         int v = it.first ;
      //         int wt = it.second ;
              
      //         if(dist[node] + wt < dist[v]){
      //             dist[v] = dist[node] + wt ;
      //         }
     
      //     }
    
      // }
    
    
       void dfs(vector<pair<int,int>> adj[] ,int node, stack<int> &st,vector<int> &vis ){
           vis[node] = 1 ;
           
           for(auto it:adj[node]){
               int v = it.first ;
               if(!vis[v]){
                   dfs(adj,v,st,vis) ;
               }
           }
           st.push(node) ;
       }
       
      
       vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
           
          vector<pair<int,int>> adj[N] ;
          
          // Generating graph 
          
          for(int i=0;i<edges.size();i++){
              int u = edges[i][0] ;
              int v = edges[i][1] ;
              int wt = edges[i][2] ;
              
              adj[u].push_back({v,wt}) ;
          }
          
          // Generate topo sort 
          
          vector<int> vis(N,0) ;
          stack<int> st ;
          
          // generating topo sort in a stack
          for(int i=0;i<N;i++){
              if(!vis[i]){
                  dfs(adj,i,st,vis) ;
              }
          }
          
          // calculating shortest path 
          
          vector<int> dist(N) ;
          
          for(int i=0;i<N;i++){
              dist[i] = 1e9 ;
          }
          
          /// initiate source node to 0 dist aaway
          dist[0] = 0 ;
          
          while(!st.empty()){
              int node = st.top() ; 
              st.pop() ;
              
              
              for(auto it : adj[node]){
                  int v = it.first ;
                  int wt = it.second ;
                  
                  // here we are looking up adjl to add dist b/w two nodes and setting minimum
                  if(dist[node] + wt < dist[v]){
                      dist[v] = dist[node] + wt ;
                  }
     
              }
          }
          
          // case if there are more component then dist will be -1 ie non reachable
          for(int i=0;i<N;i++){
              if(dist[i] == 1e9){
                  dist[i] = -1 ;
              }
          }
          
          return dist ; 
      }
  };
//Position this line where user code will be pasted.

// refer- https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it])
                dfs(it, adj, vis, st);
        }
        st.push(node);
    }
    
    void dfs3(int node, vector<vector<int>> &adjT, vector<int> &vis){
        vis[node]=1;
        
        for(auto it: adjT[node])
        {
            if(!vis[it]){
                dfs3(it, adjT, vis);
            }
        }
        return;
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        int V= adj.size();
        
        // step 1 -- calculating finish time
        vector<int> vis(V, 0);
        stack<int> st; // for storing finsiheing time
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        
        // step2 -- revere graph
        
        vector<vector<int>> adjT(V);
        
        for(int i=0; i<V; i++){
            // marking visisted to unvisited to use it again
            vis[i]=0;
            for(auto it: adj[i]){
                // i -> it
                // reverse it-> i
                
                adjT[it].push_back(i);
            }
        }
        int scc=0;
        // perform dfs to count scc
        while(!st.empty()){
            int node= st.top();
            st.pop();
            
            if(!vis[node])
            {
                scc++;
                dfs3(node, adjT, vis);
            }
        }
        return scc;
        
    }
};
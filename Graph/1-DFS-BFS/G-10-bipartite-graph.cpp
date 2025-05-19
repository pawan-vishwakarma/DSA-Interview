class Solution {
    public:
    // refer- https://leetcode.com/problems/is-graph-bipartite/
        bool bfs(int node, vector<vector<int>>& graph, vector<int> &vis){
            queue<int> q;
            q.push(node);
            vis[node]= 0;
    
            while(!q.empty()){
                int front= q.front();
                q.pop();
                for(auto it: graph[front]){
                    // filling non visited to opposite color
                    if(vis[it] == -1){
                        q.push(it);
                        vis[it] = !vis[front];
                    }
                    // if already visited then check if neigh have same color then return false
                    else if(vis[front] == vis[it]){
                        return false;
                    }
                }
            }
            return true;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            int n= graph.size();
            int m= graph[0].size();
            vector<int> vis(n, -1);
            // bool ans= true;
            for(int i=0; i<n; i++){
                if(vis[i] == -1){
                    if(bfs(i, graph, vis) == false){
                        return false;
                    }
                }
            }
            return true;
        }
    };
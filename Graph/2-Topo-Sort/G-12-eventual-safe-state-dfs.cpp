class Solution {
    public:
    // refer- https://leetcode.com/problems/find-eventual-safe-states/
    // solved using dfs
        bool dfs(int node, vector<int> &vis, vector<int> &path, vector<int> &check, vector<vector<int>>& adjL){
            vis[node]= 1;
            path[node]= 1;
            // it is notsafe considered
            check[node]=0;
    
            for(auto it: adjL[node]){
                if(!vis[it]){
                    vis[it];
                    if(dfs(it, vis, path, check, adjL)) return true;
                }
                else if(path[it]){
                    return true;
                }
            }
    
            // node is safe
            check[node]= 1;
            path[node]= 0;
            return false;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n= graph.size();
            int m= graph[0].size();
    
            vector<int> vis(n, 0);
            vector<int> check(n, 0);
            vector<int> path(n, 0);
    
            for(int i=0; i<n ;i++){
                if(!vis[i]){
                    dfs(i, vis, path,check, graph);
                }
            }
    
            vector<int> ans;
            for(int i=0; i<n; i++){
                if(check[i] == 1){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };
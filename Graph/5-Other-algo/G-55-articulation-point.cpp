#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
// refer- https://www.geeksforgeeks.org/problems/articulation-point-1/0
class Solution {
  private:
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, 
                vector<int> &mark, int time[], int low[]){
                    
        vis[node]=1;
        
        time[node]= low[node]= timer;
        timer++;
        int child=0;
        
        
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it, node, adj, vis, mark, time, low);
                
                low[node]= min(low[node], low[it]);
                
                if(low[it] >= time[node] and parent != -1){
                    mark[node]=1;
                }
                child++;
            }
            else{
                // here we are checking the steps timer instead of its parents timer
                low[node]= min(low[node], time[it]);
            }
        }
        
        // since above logic is not for node with parent as -1
        // so if the start node has more than 1 child then it is also a articulation point
        if(child > 1 and parent == -1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        vector<int> vis(V, 0);
        vector<int> markArti(V, 0);
        
        int time[V];
        int low[V];
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, adj, vis, markArti, time, low);
            }
        }
        
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(markArti[i]){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0) return {-1} ;
        return ans;
    }
};
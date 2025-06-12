// refer- https://leetcode.com/problems/critical-connections-in-a-network/submissions/1661746435/
#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], 
            vector<int> &vis, int time[], int low[], vector<vector<int>> &bridges){
        vis[node]=1;
        time[node]= low[node]= timer;
        timer++;

        for(auto it: adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){ // not visieted
                dfs(it, node, adj, vis, time, low, bridges);
                low[node]= min(low[node], low[it]);
                // check for bridge
                if(low[it] > time[node]){
                    bridges.push_back({it, node});
                }
            }
            else{
                low[node]= min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int time[n];
        int low[n];
        vector<vector<int>> bridges;

        dfs(0, -1, adj, vis, time, low, bridges);

        return bridges;

    }
};
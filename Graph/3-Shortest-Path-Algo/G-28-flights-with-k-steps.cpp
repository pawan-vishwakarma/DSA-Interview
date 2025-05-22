class Solution {
    public:
    // refer- https://leetcode.com/problems/cheapest-flights-within-k-stops/
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<pair<int, int>> adj[n];
    
            for(auto it: flights){
                adj[it[0]].push_back({it[1], it[2]});
            }
    
            queue<pair<int, pair<int,int>>> q;
            q.push({0, {src, 0}});
    
            vector<int> cost(n, 1e9);
    
            while(!q.empty()){
                int u= q.front().second.first;
                int ucost= q.front().second.second;
                int stops= q.front().first;
                q.pop();
    
                // exploring all the edges
                for(auto it: adj[u]){
                    int v= it.first;
                    int vcost= it.second;
                    int totalcost= ucost+vcost;
    
                    // increasing the stop and checking used k+1 becuase the last one will destinations
                    if(stops <= k){
                        if(cost[v] > totalcost){
                            cost[v]= totalcost;
                            q.push({stops+1, {v, totalcost}});
                        }
                    }
                }
            }
    
            return cost[dst] == 1e9? -1: cost[dst];
    
        }
    };
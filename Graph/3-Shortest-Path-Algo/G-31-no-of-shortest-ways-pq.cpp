class Solution {
    public:
    // refer- https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<pair<int,int>> adj[n];
            for(auto it: roads){
                int u= it[0];
                int v= it[1];
                int time= it[2];
    
                adj[u].push_back({v, time});
                adj[v].push_back({u, time});
            }
    
            int mod= (int)(1e9+7);
    
            priority_queue< pair<long,long>, vector<pair<long,long>>, greater<pair<long,long>>> pq;
            vector<long> dist(n, LLONG_MAX);
            vector<long> ways(n, 0);
    
            dist[0]= 0;
            // store the ways the every node 
            ways[0]= 1;
    
            // {time, node}
            pq.push({0, 0});
    
            // classsic dijkstra's algo for weighted undirected graph
            // ie using PQ instead of Queue
    
            while(!pq.empty()){
                int u= pq.top().second;
                long long utime= pq.top().first;
                pq.pop();
    
                for(auto it: adj[u]){
                    int v= it.first;
                    long long vtime= it.second;
    
                    if(dist[v] > utime+vtime){
                        dist[v]= utime+vtime;
                        // it means the v have same as u ways as v is visited by smaller route
                        ways[v]= ways[u];
                        pq.push({dist[v], v});
                    }
                    else if(dist[v] == utime+vtime){
                        // it means that ways will add up as there exist more than 1 way with same smaller time/dist
                        ways[v] = (ways[v]+ways[u])%mod;
                    }
                }
            }
            return ways[n-1];
        }
    };
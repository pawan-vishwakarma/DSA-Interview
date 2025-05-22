class Solution {
    public:
    // refer- https://leetcode.com/problems/network-delay-time/
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            
            // created adjlist
            vector<pair<int,int>> adj[n+1];
            for(auto it: times){
                int u= it[0];
                int v= it[1];
                int tm= it[2];
    
                adj[u].push_back({v, tm});
            }
    
            // time array to store minimum time 
            vector<int> time(n+1, 1e9);
    
            // queue to store 
            // queue<pair<int, int>> q;
            // queue is ineffient in weighted graphs with different weights other than 1
            // thereofre using pq
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
            q.push({0, k});
            time[k]= 0;
    
            int maxi= -1e9;
    
            while(!q.empty()){
                int u= q.top().second;
                int utime= q.top().first;
                q.pop();
    
                for(auto it: adj[u]){
                    int v= it.first;
                    int vtime= it.second;
    
                    if(time[v] > utime+vtime){
                        time[v]= vtime+utime;
                        q.push({time[v], v});
                    }
    
                }
            }
    
            for(int i=1; i<=n ;i++) maxi= max(maxi, time[i]);
            return maxi == 1e9? -1 : maxi;
        }
    };
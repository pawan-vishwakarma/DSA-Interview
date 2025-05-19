class Solution {
    public:
        vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    
            vector<int> adjL[2001];
    
            for(auto edge: prerequisites){
                int u= edge[1];
                int v= edge[0];
    
                adjL[u].push_back(v);
            }
            
            int indegree[2001]= {0};
            for(int i=0; i<n ;i++){
                for(auto it: adjL[i]){
                    indegree[it]++;
                }
            }
    
            // pushing 0 indegree
            queue<int> q;
            for(int i=0; i<n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            vector<int> ans;
            while(!q.empty()){
                int front= q.front();
                q.pop();
    
                ans.push_back(front);
    
                for(auto it: adjL[front]){
                    indegree[it]--;
                    if(indegree[it] == 0) q.push(it);
                }
            }
            if(ans.size() == n){
                return ans;
            }
            return { };
        }
    };
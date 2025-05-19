class Solution {
    public:
        bool canFinish(int n, vector<vector<int>>& prereq) {
    
            vector<int> adj[n] ;
            for(auto it : prereq){
                adj[it[1]].push_back(it[0]) ;
            }
    
            int indegree[2000] = {0} ;
    
            for(int i=0;i<n;i++){
                for(auto it : adj[i]){
                    indegree[it]++ ;
                }
            }
    
            queue<int> q ;
    
            for(int i=0;i<n;i++){
                if(indegree[i] == 0){
                    q.push(i) ;
                }
            }
    
            vector<int> ans ;
            while(!q.empty()){
                int f = q.front() ;
                q.pop() ;
    
                ans.push_back(f)  ;
    
                for(auto it : adj[f]){
                    indegree[it]-- ;
    
                    if(indegree[it] == 0){
                        q.push(it) ;
                    }
                }
            }
    
            if(n == ans.size()){
                return true ;
            }
    
            return false ;
    
        }
    };
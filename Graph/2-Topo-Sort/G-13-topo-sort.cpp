class Solution
{
    // refer- https://www.geeksforgeeks.org/problems/topological-sort/1
	public:
	//Function to return list containing vertices in Topological order. 
	
	
	void dfs( vector<int> adj[],int i,stack<int> &s,int vis[]){
	    vis[i] = 1 ;
	    
	    for(auto it : adj[i]){
	        if(!vis[it])
	            dfs(adj,it,s,vis) ;
	    }
	    s.push(i) ;
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0} ;
	    
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++ ;
	        }
	    }
	    
	    queue<int> q ;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i] == 0){
	            q.push(i) ;
	        }
	    }
        vector<int> ans ;
	
	    while(!q.empty()){
	        int f = q.front() ;
	       // s.push(f) ;
	        q.pop() ;
	        ans.push_back(f) ;
	        for(auto it : adj[f]){
	            indegree[it]-- ;
	            if(indegree[it] == 0 ){
	                q.push(it) ;
	            }
	        }
	        
	    }
	      
	    return ans ;
	    
	}
};
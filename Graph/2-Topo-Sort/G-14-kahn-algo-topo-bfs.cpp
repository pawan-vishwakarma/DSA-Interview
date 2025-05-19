vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0} ;
	    
        // calculate indegree
	    for(int i=0;i<V;i++){
	        for(auto it : adj[i]){
	            indegree[it]++ ;
	        }
	    }
	    
	    queue<int> q ;


	    // initiate with 0 indegree nodes
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
                // reduce indegree as visit
                // note there is no need of vis array
	            indegree[it]-- ;
	            if(indegree[it] == 0 ){
	                q.push(it) ;
	            }
	        }
	        
	    }
	      
	    return ans ;
	    
	}
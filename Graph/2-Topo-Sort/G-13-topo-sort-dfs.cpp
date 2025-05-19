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
		int vis[V]= {0};
		stack<int> st;

	    for(int i=0; i<V; i++){
			if(!vis[i]){
				dfs(adj, i, st, vis);
			}
		}
		vector<int>ans;
		while(!st.empty()){
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};
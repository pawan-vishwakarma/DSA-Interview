// User function Template for C++
#include <bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    
    public:
        DisjointSet(int n){
            // n+1 for 1 based indexing
            rank.resize(n+1, 0);
            parent.resize(n+1, 0);
            
            // initiate with everyone is their own parent
            for(int i=0; i<=n; i++){
                parent[i]=i;
            }
        }
        
        int findPar(int n){
            if(parent[n] == n){
                return n;
            }
            //return findPar(parent[n]); //array will make path for parents
            return parent[n] = findPar(parent[n]); // path compression 
            
        }
        
        void unionByRank(int u, int v){
            // find parent of u, v
            int upar= findPar(u);
            int vpar= findPar(v);
            if(upar == vpar)return; // same parent part of same component
            
            // merge the u or v based on their parents rank
            if(rank[upar] < rank[vpar]){
                parent[upar]= vpar;
                
            }
            else if(rank[upar] > rank[vpar]){
                parent[vpar]= upar;
            }
            else{
                // merge v to u
                parent[vpar]= upar;
                // increase rank of u
                rank[upar]++;
            }
            
        }
};


class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        vector<pair<int,pair<int,int>>> adj;
        
        for(auto edge: edges){
            int wt= edge[2];
            int u= edge[0];
            int v= edge[1];
            
            adj.push_back({wt, {u, v}});
        }
        
        sort(adj.begin(), adj.end());
        
        DisjointSet ds(V);
        // now traverse the edges and make the union using union op of disjoint DS
        
        int mstWt=0;
        for(auto it: adj){
            int wt= it.first;
            int u= it.second.first;
            int v= it.second.second;
            
            // when u and v have diff parent then only we will merge them 
            // and then only we putt the edge b/w them and count the wt of the edge
            
            if(ds.findPar(u) != ds.findPar(v)){
                mstWt += wt;
                ds.unionByRank(u, v);
            }
            
        }
        
        return mstWt;
    }
};
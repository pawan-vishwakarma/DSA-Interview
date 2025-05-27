#include<bits/stdc++.h>
using namespace std;

//refer- https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class DisjointSet{
public:
    vector<int> rank, parent;

    DisjointSet(int v){
        rank.resize(v+1, 0);
        parent.resize(v+1, 0);

        for(int i=0; i<=v; i++){
            parent[i]= i;
        }
    }

    int find(int u){
        if(parent[u] == u){
            return u;
        }
        return parent[u]= find(parent[u]);
    }

    void unionByRank(int u, int v){
        int upar= find(u);
        int vpar= find(v);

        if(rank[upar] > rank[vpar]){
            parent[vpar]= upar;
        }
        else if(rank[upar] < rank[vpar]){
            parent[upar]= vpar;
        }
        else{
            parent[upar]= vpar;
            rank[vpar]++;
        }
    }
};

// Here it is disjoint set union approach 
// can also be solved using count of component method
class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) {
        // atleast require n-1 conn to connect n nodes
        if(connections.size() < n-1) return -1;

        DisjointSet ds(n);
        int ans=0;
        for(auto it: connections){
            int u= it[0], v= it[1];

            if(ds.find(u) != ds.find(v)){
                ds.unionByRank(u, v);
                // incresing the conn count
                ans++;
            } 
        }
        // reamining conn to connect whole netwrk
        return n-ans-1;
    }
};
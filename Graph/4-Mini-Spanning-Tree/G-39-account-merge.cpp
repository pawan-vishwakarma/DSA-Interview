#include<bits/stdc++.h>
using namespace std;

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


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // declare disjoint
        int n= accounts.size();
        DisjointSet ds(n);
        // this will store <email, int> here int is number we have chosen as group
        unordered_map<string, int> um;
        for(int i=0; i<accounts.size(); i++){
            // temp store vector of emails
            vector<string> temp= accounts[i];
            for(int j=1; j<temp.size(); j++){
                // temp[i] is individual email
                string email= temp[j];
                // doing lookup if not found mail then added to ith group
                if(um.find(email) == um.end()){
                    um[email]= i;
                }else{
                    // if found some email then make union of ith node
                    // and um[email] ie old node
                    ds.unionByRank(um[email], i);
                }
            }
        }

        // now this map is holding mergerd acc emails with node number
        unordered_map<int, vector<string>> merge;
        for(auto it: um){
            int parent= ds.find(it.second);
            merge[parent].push_back(it.first);
        }

        // ans vector
        vector<vector<string>> ans;

        for(auto it: merge){
            vector<string> temp;
            // here we are extracting the first word of accounts ie "john", "marie" etc
            temp.push_back(accounts[it.first][0]);
            // sorting the vector taken from merged map
            sort(it.second.begin(), it.second.end());
            // insert these emails vector to temp;
            temp.insert(temp.end(), it.second.begin(), it.second.end());
            // putting the temp to ans
            ans.push_back(temp);
        }
        return ans;
    }
};
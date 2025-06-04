#include<bits/stdc++.h>
using namespace std;
// User function Template for C++
class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    
    public:
        DisjointSet(int n){
            // n+1 for 1 based indexing
            rank.resize(n+1, 0);
            size.resize(n+1, 0);
            parent.resize(n+1, 0);
            
            // initiate with everyone is their own parent
            for(int i=0; i<=n; i++){
                parent[i]=i;
                // used when using disjoint set DS using size
                size[i]=1;
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

        // another type ie ds by size
        void unionBySize(int u, int v){
            int upar= findPar(u);
            int vpar= findPar(v);
            if(size[upar] > size[vpar]){
                parent[vpar]= upar;
                size[upar] += size[vpar];
            }
            else{
                parent[upar]= vpar;
                size[vpar] += size[upar];
            }
        }
            
};



class Solution {
  public:
    bool isvalid(int r, int c, int n, int m){
        if(r >= 0 and r < n and c >= 0 and c < m) return true;
        return false;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        
        vector<int> ans;
        int cnt=0;
        
        for(auto it: operators){
            int r= it[0];
            int c= it[1];
            
            if(vis[r][c]){
                ans.push_back(cnt);
                continue;
            }
            
            vis[r][c]= 1;
            cnt++;
            
            // visitng 4 directions
            int dr[]= {-1, 0, 1, 0};
            int dc[]= {0, 1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nr= r+dr[i];
                int nc= c+dc[i];
                
                if(isvalid(nr, nc, n, m)){
                    if(vis[nr][nc]){
                        int nodeN= r*m+c;
                        int nnodeN= nr*m+nc;
                        
                        if(ds.findPar(nodeN) != ds.findPar(nnodeN)){
                            cnt--;
                            ds.unionBySize(nodeN, nnodeN);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

#include<bits/stdc++.h>
using namespace std;
// refer- https://www.geeksforgeeks.org/problems/maximum-connected-group/1
// User function Template for C++
class DisjointSet{
    vector<int> rank;
    vector<int> parent;
    
    public:
    vector<int> size;
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
    bool isvalid(int r, int c, int n){
        return (r >= 0 and r < n and c >= 0 and c < n);
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n= grid.size();
        DisjointSet ds(n*n);
        
        // creating ds data structure 
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                
                if(grid[r][c] == 0) continue;
                
                int dr[]= {-1, 0, 1, 0};
                int dc[]= {0, 1, 0, -1};
                
                for(int i=0; i<4; i++){
                    int nr= r+dr[i];
                    int nc= c+dc[i];
                    
                    if(isvalid(nr, nc, n) and grid[nr][nc] ) {
                        int nodeN= r*n+c;
                        int nnodeN= nr*n+nc;
                        if(ds.findPar(nodeN) != ds.findPar(nnodeN)){
                            ds.unionBySize(nodeN, nnodeN);
                        }
                    }
                }
            }
        }
        
        // now iterate 0 in grid and tried conncecting them to disjoint set
        int ans=0, flag=0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                
                if(grid[r][c] == 0){
                    flag= 1;
                    
                    set<int> st;
                    int dr[]= {-1, 0, 1, 0};
                    int dc[]= {0, 1, 0, -1};
                    
                    for(int i=0; i<4; i++){
                        int nr= r+dr[i];
                        int nc= c+dc[i];
                        
                        if(isvalid(nr, nc, n) and grid[nr][nc] ) {
                            int nodeN= r*n+c;
                            int nnodeN= nr*n+nc;
                            if(ds.findPar(nodeN) != ds.findPar(nnodeN)){
                                // ds.unionBySize(nodeN, nnodeN);
                                st.insert(ds.findPar(nnodeN));
                            }
                        }
                    }
                    
                    int tempsize= 0;
                    for(auto x: st){
                        tempsize += ds.size[x];
                    }
                    ans = max(tempsize, ans);
                }
                
            }
        }
        
        return flag == 0 ? n*n : ans+1;
    }
};

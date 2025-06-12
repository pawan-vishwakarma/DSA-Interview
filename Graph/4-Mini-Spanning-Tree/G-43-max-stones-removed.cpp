// refer- https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        
        int mr=0;
        int mc=0;
        
        for(auto it: stones){
            mr= max(mr, it[0]);
            mc= max(mc, it[1]);
        }
        
        DisjointSet ds(mr+mc+1);
        unordered_map<int, int> um; // to store stones in same row, col
        
        for(auto it: stones){
            int noderow= it[0];
            int nodecol= it[1]+mr+1;
            
            ds.unionBySize(noderow, nodecol);
            
            um[noderow]=1;
            um[nodecol]=1;
            
        }
        
        // iterate all related stones in um
        int cnt=0;
        for(auto it: um){
            if(ds.findPar(it.first) == it.first){
                cnt++; // counting no of connected components
            }
        }
        
        return n-cnt;
    }
};
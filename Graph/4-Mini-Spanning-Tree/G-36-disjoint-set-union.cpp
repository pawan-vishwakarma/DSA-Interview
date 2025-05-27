#include <bits/stdc++.h>
using namespace std;
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


int main() {
	DisjointSet ds(7);
	// ByRank
        // ds.unionByRank(1,2);
        // ds.unionByRank(2,3);
        // ds.unionByRank(4,5);
        // ds.unionByRank(6,7);
        // ds.unionByRank(5,6);
        
        // if(ds.findPar(3) == ds.findPar(7)){
        //     cout<<"same"<<endl;
        // }
        // else{
        // cout<<"Not same"<<endl;
        // }
        
        // ds.unionByRank(3,7);
        
        // if(ds.findPar(3) == ds.findPar(7)){
        //     cout<<"same"<<endl;
        // }
        // else{
        // cout<<"Not same"<<endl;
        // }

    // By Size    
        ds.unionBySize(1,2);
        ds.unionBySize(2,3);
        ds.unionBySize(4,5);
        ds.unionBySize(6,7);
        ds.unionBySize(5,6);
        
        if(ds.findPar(3) == ds.findPar(7)){
            cout<<"same"<<endl;
        }
        else{
        cout<<"Not same"<<endl;
        }
        
        ds.unionBySize(3,7);
        
        if(ds.findPar(3) == ds.findPar(7)){
            cout<<"same"<<endl;
        }
        else{
        cout<<"Not same"<<endl;
        }

	return 0;

}

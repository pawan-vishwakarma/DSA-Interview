
class Solution {
    // refer- https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        // the crux of the problem is number of node will always be 0-9999
        // why ?? -> because we have given that we need to perform mod oprtn at every multiply
        // it led to restriction of the numbers b/w 0 and 9999 and never more than that
        // therefore steps of size 1e5
        
        vector<int> steps(1e5, 1e9);
        int mod = 100000;
        
        queue<pair<int, int>>q;
        q.push({0, start});
        
        while(!q.empty()){
            int step= q.front().first;
            int num= q.front().second;
            q.pop();
            
            if(num == end) return step;
            
            for(int i: arr){
                int mul= (num*i)%mod;
                if(steps[mul] > step+1){
                    steps[mul]= step+1;
                    q.push({step+1, mul});
                }
            }
        }
        return -1;
    }
};

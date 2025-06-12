#include <bits/stdc++.h>
using namespace std;
// refer- https://leetcode.com/problems/swim-in-rising-water/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n= grid.size();

        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});

        vector<vector<int>> visit(n, vector<int>(n ,0));

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        while(!pq.empty()){
            auto it= pq.top();
            int high= it.first;
            int x= it.second.first;
            int y= it.second.second;

            if(x == n-1 and y == n-1) return high;
            pq.pop();

            for(int i=0; i<4; i++){
                int nx= x+dr[i];
                int ny= y+dc[i];

                if(nx >= 0 and nx < n and ny >= 0 and ny < n and !visit[nx][ny]){
                    visit[nx][ny]=1;
                    pq.push({max(high, grid[nx][ny]), {nx, ny}});
                }
            }
        }
        return 0;
    }
};

class Solution {
    public:
        // refer- https://leetcode.com/problems/flood-fill/
        void dfs(int row, int col, vector<vector<int>>& image, vector<vector<int>>& ans, 
                int oldcolor, int color, int delrow[], int delcol[]){
            ans[row][col]= color;
            int n= image.size();
            int m= image[0].size();
            for(int i=0; i<4; i++){
                int nrow= row+ delrow[i];
                int ncol= col+ delcol[i];
                if(nrow >= 0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol] == oldcolor and ans[nrow][ncol] != color){
                    dfs(nrow, ncol, image, ans, oldcolor, color, delrow, delcol);
                }
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            vector<vector<int>> ans= image;
            int oldcolor= image[sr][sc];
            int delrow[]= {-1, 0, 1, 0};
            int delcol[]= {0, 1, 0, -1};
            dfs(sr, sc, image, ans, oldcolor, color, delrow, delcol);
            return ans;
        }
    };
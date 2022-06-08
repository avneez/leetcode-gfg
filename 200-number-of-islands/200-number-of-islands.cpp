class Solution {
public:

    int x[8] = {0,0,1,-1};
    int y[8] = {1,-1,0,0};
    void dfs(int i, int j, vector<vector<char>>& grid, int n, int m){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0') return;

        if(grid[i][j]=='1'){
            grid[i][j]='0';
            for(int dir=0; dir<4; dir++){
                dfs(i+x[dir], j+y[dir], grid, n, m);
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    
        int c=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,n,m);
                    c++;
                }
            }
        }
        return c;
    }
};
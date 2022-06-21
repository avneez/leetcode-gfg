class Solution {
public:
    int ans=0;

    void dfs(int i, int j, vector<vector<int>>& grid, int bag){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0) return;
        
        int x[4] ={0,1,-1,0};
        int y[4] ={1,0,0,-1};
        
        int temp = grid[i][j];
        bag+=grid[i][j];
        grid[i][j] = 0;
        ans=max(ans, bag);
        
        for(int d=0; d<4; d++){
            dfs(i+x[d],j+y[d],grid,bag);
        }
//         dfs(i+1,j,grid,bag);
//         dfs(i-1,j,grid,bag);
//         dfs(i,j-1,grid,bag);
//         dfs(i,j+1,grid,bag);
        
        grid[i][j]=temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]!=0)
                    dfs(i,j,grid,0);
            }
        }
        return ans;
    }
};
class Solution {
public:
    int ans=0;
    void dfs(int i, int j, vector<vector<int>>& grid, int bag){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0) return;
        
        bag+=grid[i][j];
        ans=max(ans, bag);
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        dfs(i+1,j,grid,bag);
        dfs(i-1,j,grid,bag);
        dfs(i,j-1,grid,bag);
        dfs(i,j+1,grid,bag);
        
        grid[i][j]=temp;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(i,j,grid,0);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int ans = 0;
    
//     void dfs(vector<vector<int>> &grid, int i, int j, int gold)
//     {
//         if(i<0 or j<0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 0)
//             return;
        
//         gold += grid[i][j];
//         ans = max(ans, gold);
        
//         int temp = grid[i][j];
//         grid[i][j] = 0;

//         dfs(grid, i+1, j, gold);
//         dfs(grid, i-1, j, gold);
//         dfs(grid, i, j+1, gold);
//         dfs(grid, i, j-1, gold);
        
//         grid[i][j] = temp;    // Backtrack
//     }
    
//     int getMaximumGold(vector<vector<int>>& grid) 
//     {
//         for(int i=0; i<grid.size(); i++)
//             for(int j=0; j<grid[0].size(); j++)
//                 dfs(grid, i, j, 0);
//         return ans;
//     }
// };
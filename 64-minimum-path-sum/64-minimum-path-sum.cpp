class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i==m-1 and j==n-1) dp[i][j]=grid[i][j];
                else if(i==m-1) dp[i][j]= dp[i][j+1] + grid[i][j];
                else if(j==n-1) dp[i][j]= dp[i+1][j] + grid[i][j];
                else {
                    dp[i][j]=min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};

        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) dp[i][j]=grid[i][j];
//                 else{
//                     int up=INT_MAX,left=INT_MAX;
//                     if(i>0) up=dp[i-1][j];
//                     if(j>0) left=dp[i][j-1];
//                    dp[i][j]= min(up,left)+grid[i][j];
//                 }
//             }
//         }
        
//         return dp[m-1][n-1];
//     }
// };
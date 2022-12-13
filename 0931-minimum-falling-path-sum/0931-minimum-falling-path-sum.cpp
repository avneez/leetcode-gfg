class Solution {
public:
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n=matrix[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] += min({matrix[i-1][j],matrix[i-1][max(0,j-1)],matrix[i-1][min(m-1,j+1)]});
                // cout<<dp[i][j]<<" ";
            }
        }
        return *min_element(matrix[m-1].begin(),matrix[m-1].end());
    }
};

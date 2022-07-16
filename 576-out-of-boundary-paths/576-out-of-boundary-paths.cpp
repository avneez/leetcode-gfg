class Solution {
public:
    long long mod = 1e9+7;
    int dp[51][51][51];
    
    int dfs(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow>=m || startColumn>=n || startRow<0 || startColumn<0) return 1;
        if(maxMove<=0) return 0;
        if(dp[startRow][startColumn][maxMove]!=-1) return dp[startRow][startColumn][maxMove];
        
        long long up = dfs(m,n, maxMove-1, startRow+1, startColumn);
        long long down = dfs(m,n, maxMove-1, startRow-1, startColumn);
        long long left = dfs(m,n, maxMove-1, startRow, startColumn-1);
        long long right = dfs(m,n, maxMove-1, startRow, startColumn+1);
        
        dp[startRow][startColumn][maxMove] = (up + down + left + right)%mod;
        return dp[startRow][startColumn][maxMove];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};
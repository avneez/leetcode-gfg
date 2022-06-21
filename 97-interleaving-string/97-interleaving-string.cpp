class Solution {
public:
    int dp[101][101];
    bool solve(string s1, string s2, string s3, int m, int n, int len){
        if(len==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        
        int a=0, b=0;
        if(m-1>=0 and s1[m-1]==s3[len-1]) a = solve(s1,s2,s3,m-1,n,len-1);
        if(n-1>=0 and s2[n-1]==s3[len-1]) b = solve(s1,s2,s3,m,n-1,len-1);
        
        return dp[m][n] = a or b;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int len = s3.size();
        if(m+n!=len) return 0;
        dp[m][n];
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3,m,n,len);
    }
};
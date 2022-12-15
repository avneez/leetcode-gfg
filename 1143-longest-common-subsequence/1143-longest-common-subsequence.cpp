class Solution {
public:
//     int find(int i,int j,string s1,string s2,vector<vector<int>>& dp){
     
//         if(i<0 || j<0) return 0;
//         if(dp[i+1][j+1] != -1) return dp[i+1][j+1];

//         if(s1[i]==s2[j])        {
//             return dp[i+1][j+1] = (1+find(i-1,j-1,s1,s2,dp));
//         }
//         return dp[i+1][j+1] = max(find(i-1,j,s1,s2,dp),find(i,j-1,s1,s2,dp));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
//         vector<vector<int>> dp(n+1,vector<int> (m+1,-1));

//         return find(n-1,m-1,text1,text2,dp);
        
        //tabulation
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);         
            }
        }

        return dp[n][m];
    }
};
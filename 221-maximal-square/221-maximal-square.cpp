class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int >> dp(n,vector<int>(m));
        int ret=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    dp[i][j]=0;
                
                else
                {
                    int a=0,b=0,c=0;
                    
                    if(i!=0 && j!=0)
                        a=dp[i-1][j-1];
                    
                    if(i!=0)
                        b=dp[i-1][j];
                    
                    if(j!=0)
                        c=dp[i][j-1];
                    
                    dp[i][j]=min(a,min(b,c))+1;
                    
                    if(ret<dp[i][j])
                    {
                        ret=dp[i][j];
                    }
                }
            }
        }
        return ret*ret;
    }
};
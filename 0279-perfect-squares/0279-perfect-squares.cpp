// class Solution {
// public:
//     int solve(int n){
//         vector<int>dp(n + 1, INT_MAX);
//         dp[0] = 0; 
//         for (int target = 1; target <= n; target++){
//             int mnCount = INT_MAX;
//             for (int num = 1; num <= sqrt(target); num++){
//                 int sqNum = num * num;
//                 int currCount = 1 + dp[target - sqNum];
//                 mnCount = min(mnCount, currCount);
//             }
//             dp[target] = mnCount;
//         }
//         return dp[n];
//     } 
//     int numSquares(int n) {
//         return solve(n);
//     }
// };

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,1000000);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j*j<=i;j++)
                dp[i]=min(dp[i],1+dp[i-j*j]);
        }
        return dp[n];
    }
};
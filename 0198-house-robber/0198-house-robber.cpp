class Solution {
public:
    int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n+2,0);
        
//         for (int i = n-1; i >= 0; i--)
//             dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
    
//         return dp[0];
        

        int evenPos_Sum=0 , oddPos_Sum=0 , max_sum=0; 
       
        for(int i=0;i<nums.size();i++){
        
            if(i%2==0){
                evenPos_Sum+=nums[i];
                evenPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
    
            if(i%2!=0){
                oddPos_Sum+=nums[i];
                oddPos_Sum = max(evenPos_Sum,oddPos_Sum);
            }
        }
   
        max_sum = max(evenPos_Sum,oddPos_Sum);
        return max_sum;
    }
};
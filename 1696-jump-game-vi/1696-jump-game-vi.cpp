class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> dp(n);
//         dp[n-1]=nums[n-1];
        
//         priority_queue<pair<int,int>> maxh;
//         maxh.push({dp[n-1],n-1});
        
//         for(int i=n-2; i>=0; i--){
//             while(maxh.size() and maxh.top().second>i+k){
//                 maxh.pop();
//             }
//                 dp[i]= maxh.top().first+nums[i];
//                 maxh.push({dp[i],i});
//         }
//         return dp[0];
//     }
        
        int n=nums.size();
        deque<int> d{0};
        
        for(int i=1; i<n; i++){
            if(d.front()+k<i) 
                d.pop_front();
            nums[i] += nums[d.front()];
            while(!d.empty() and nums[d.back()]<=nums[i])
                d.pop_back();
            d.push_back(i);
        }
        return nums.back();
    }
};

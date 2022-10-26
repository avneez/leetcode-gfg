class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum[n+1];
        for(int i=1; i<=n; i++){
            sum[i]=sum[i-1]+nums[i-1];
        }  
        set<int> s;
        for(int i=2;i<=n;i++){
            s.insert(sum[i-2]%k);
            if(s.count(sum[i]%k))
                return true;
        }
        return false;
    }
};
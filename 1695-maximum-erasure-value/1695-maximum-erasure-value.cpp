class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> mp; 
        int sum=0; int maxsum=0; int l=0;
        for(auto i:nums){ 
            while(mp.find(i)!=mp.end()){
                sum-=nums[l];
                mp.erase(nums[l]);
                l++;
            }
            sum+=i;
            mp.insert(i);
            maxsum = max(sum, maxsum);
        }
        return maxsum;
    }
};
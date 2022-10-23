class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> mp(nums.begin(),nums.end());
        int sum=(n*(n+1))/2;
        int wsum=0, s=0;
        for(auto it:nums) wsum+=it;
        for(auto it:mp) s+=it;
        return {wsum-s, sum-s};
    }
};
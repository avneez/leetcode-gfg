class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        if(n==1) return nums;
        if(n==2 && nums[0]!=nums[1]) return nums;
        if(n==2 && nums[0]==nums[1]) {ans.push_back(nums[0]); return ans;}
        
        unordered_map<int,int> m;
        for(auto i:nums) m[i]++;
        for(auto it:m){
            if(it.second>n/3) ans.push_back(it.first);
        }
        
        return ans;
    }
};
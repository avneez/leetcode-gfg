class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()/2];
        
        int c=0;
        int ans=-1;
        
        for(int num:nums){
            if(c==0) ans=num;
            if(num==ans) c+=1;
            else c-=1;
        }
        return ans;
     }
};
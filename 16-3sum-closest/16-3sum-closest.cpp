class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans =0; int mini=INT_MAX;
        int n=nums.size();
        for(int i=0; i<n-2; i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                int diff = abs(sum-target);
                if(diff<mini){
                    mini=diff;
                    ans=sum;
                }
                if(sum<target) j++;
                else k--;
            }
        }
        return ans;
    }
};
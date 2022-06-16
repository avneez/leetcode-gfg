class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return {};
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i==0 or (nums[i]!=nums[i-1] and i>0)){
                int low=i+1, high=nums.size()-1, sum=0-nums[i];
                
                while(low<high){
                    if(nums[low]+nums[high]==sum){
                        vector<int> temp;
                        // temp.push_back(nums[i]);
                        // temp.push_back(nums[low]);
                        // temp.push_back(nums[high]);
                        temp.insert(temp.end(), {nums[i], nums[low], nums[high]});
                        res.push_back(temp);
                    
                        while(low<high and nums[low]==nums[low+1]) low++;
                        while(low<high and nums[high]==nums[high-1]) high--;
                    
                        low++; high--;
                    }
                    else if(nums[low]+nums[high]<sum) low++;
                    else high--;
                }
            }
        }
        return res;
    }
};
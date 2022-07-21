class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums, int i, vector<int> subs){
        if(i==nums.size()){
            ans.push_back(subs);
            return;
        } 
        generate(nums,i+1,subs);    //don't pick
        
        subs.push_back(nums[i]);    //pick and call for next
        generate(nums,i+1,subs);
        subs.pop_back();            //backtrack
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        generate(nums,0,sub);
        return ans;
    }
};
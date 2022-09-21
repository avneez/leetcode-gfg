class Solution {
public:
    int sumEven(vector<int>& nums){
        int sum=0;
        for(auto &i:nums){
            if(i%2==0) sum+=i;
        }
        return sum;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> ans;
        int s=sumEven(nums);
        
        for(int i=0; i<n; i++){
            int index = queries[i][1]; int val = queries[i][0];
            if(nums[index]%2==0) s-=nums[queries[i][1]];   //if even deduct the sum for processing
            nums[index] += val;
            if(nums[index]%2==0) s+=nums[index];   //if even then update the sum
            ans.push_back(s);
        }
        return ans;
    }
};
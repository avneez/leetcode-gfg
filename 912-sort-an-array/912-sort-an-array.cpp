class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> p;
        int n=nums.size();
        for(int x:nums){
            p.push(x);
        }
        
        for(int i=0;i<n;i++){
            nums[i]=p.top();
            p.pop();
        }
        return nums;
    }
};
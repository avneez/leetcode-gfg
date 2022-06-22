class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> mn;
        for(int i=0; i<nums.size(); i++){
            mn.push(nums[i]);
            if(mn.size()>k) mn.pop();
        }
        return mn.top();       
    }
};
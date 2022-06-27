class Solution{
public:

    int firstMissingPositive(vector<int>& nums) {
        int curr = 0, n = nums.size(); // take 2 pointers
        while( curr < n){ // iterating through nums array
            // if indexed el is >0 && <=n && not equal to index
            if(nums[curr] > 0 && nums[curr] <= n && nums[curr] != nums[nums[curr] - 1])
                swap(nums[curr],nums[nums[curr] - 1]); // swap them to change into matching
            else
                curr++;
        }
        for(int i = 0;i<n;i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return n + 1;
    }
};
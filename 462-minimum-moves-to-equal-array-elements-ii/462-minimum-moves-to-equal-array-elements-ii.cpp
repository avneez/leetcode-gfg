class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long mid=0, sum = 0, cnt=0;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        
        for(auto i: nums) sum+=i;
        mid = nums[n/2];
    
        for(int i=0; i<n; i++){
            cnt+=abs(nums[i]-mid);
        }
        return cnt;
    }
};
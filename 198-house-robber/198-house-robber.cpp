class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
         int a=0,b=0,c=0;
        int temp;
        for(int i=0;i<n;i++){
        temp = max(c,b) + nums[i];
        c=b;
        b=a;
        a=temp;
    }
    return max(a,b);
        
    }
};
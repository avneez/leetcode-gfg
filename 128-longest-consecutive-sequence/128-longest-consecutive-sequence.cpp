class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
             
        if(nums.size()==0) return 0;
        
        int max_res=1;
        unordered_set<int> m;
        
        for(int i=0;i<nums.size();i++)  m.insert(nums[i]); 
            
        for(int i=0;i<nums.size();i++) {
            if(m.count(nums[i]-1))  continue;   
            int res = 1;
            while(m.count(nums[i]+res)) res++;  
            max_res = max(res,max_res);
        }
        return max_res;
    }
};
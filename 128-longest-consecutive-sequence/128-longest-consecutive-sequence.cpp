class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
             
        if(nums.size()==0) return 0;
        
        set<int> s;
        for(int i=0;i<nums.size();i++)  s.insert(nums[i]); 
         
        int max_res=0;
        for(int i=0;i<nums.size();i++) {
            if(!s.count(nums[i]-1)) { 
                int curnum = nums[i];
                int res = 1;
                while(s.count(curnum+1)){
                    curnum++; res++;
                } 
                max_res = max(res,max_res);
            }
        }
        return max_res;
    }
};
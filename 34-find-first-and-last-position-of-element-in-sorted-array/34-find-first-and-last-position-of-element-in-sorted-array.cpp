class Solution {
public:
    
    int firstOcc(vector<int>& nums, int target){
        int s=0;
        int e=nums.size()-1;
        int ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
           
            if (target==nums[mid]) {
                ans=mid;
                e= mid-1;
            }
            else if (target>nums[mid]) s=mid+1;
            else e=mid-1;
            
            mid = s+(e-s)/2;
        }
        return ans;
    }
    
    int lastOcc(vector<int>& nums, int target){
        int s=0;
        int e=nums.size()-1;
        int ans = -1;
        int mid = s+(e-s)/2;
        
        while(s<=e){
            
            if (target==nums[mid]){
                ans=mid;
                s=mid+1;
            }
            else if (target>nums[mid]) s=mid+1;
            else e=mid-1;
            
            mid = s+(e-s)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v;
        v.push_back(firstOcc(nums, target));
        v.push_back(lastOcc(nums, target));
        
        return v;
    }
};
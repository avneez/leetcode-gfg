class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right = n-1;
        int ans = 0;
        
        while(left<=right){
            ans = max(min(height[left],height[right])*(right-left),ans);
            if(height[left]<=height[right]){
                left++;
            }
            else right--;
        }
        return ans;
    }
};
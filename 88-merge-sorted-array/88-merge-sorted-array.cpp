class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j = 0; int k = nums1.size()-1;
        for (i=0; i<nums1.size()&& j<nums2.size(); i++){
            if(nums1[i]==0){
                nums1[i]=nums2[j];
                j++;
            }
        }
        sort(nums1.begin(), nums1.end());
    }
};
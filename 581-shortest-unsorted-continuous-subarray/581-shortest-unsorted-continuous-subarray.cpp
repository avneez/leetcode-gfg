class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums1(nums.begin(), nums.end());              // copying into new vector
        sort(nums1.begin(), nums1.end());                          // sorting new vector
        int n = nums.size(), s = 0, e = n - 1;                // initalizing start and end
        while (s < n && nums[s] == nums1[s]) {                 // counting size left sorted subarray
            s++;
        }
        while (e > s && nums[e] == nums1[e]) {              // counting size right sorted subarray
            e--;
        }
        return e + 1 - s;                             // returning size of right subarray - left subarray
    }
};
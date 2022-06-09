class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int l=0;
        int r=numbers.size()-1;
        
        while(l<r){
            int currsum = numbers[l]+numbers[r];
            if(currsum==target){
                v.push_back(l+1);
                v.push_back(r+1);
                break;
            }
            else if(currsum<target) l++;
            else r--;
        }
        return v;
    }
};
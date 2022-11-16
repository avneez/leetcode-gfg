class Solution {
public:
    
	void permuteRecursive(vector<int> &num, int index, vector<vector<int> > &result)	{
		if (index >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = index; i < num.size(); i++) {
		    swap(num[index],num[i]);
		    permuteRecursive(num, index + 1, result);
		    swap(num[index], num[i]);  //backtrack
		}
    }
    
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    
	    permuteRecursive(num, 0, result);
	    return result;
    }

};


// class Solution {
// public:
// 	vector<vector<int>> permute(vector<int>& nums) {
// 		sort(nums.begin(), nums.end());
// 		vector<vector<int>>ans;
// 		do{
// 			ans.push_back(nums);
// 		}
//         while(next_permutation(nums.begin(), nums.end()));
// 		return ans;
// 	}
// };
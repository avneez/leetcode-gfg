class Solution {
public:
    void combination(int start, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& res){
        int n = candidates.size();
        if (start==n){
            if(target==0){ 
            res.push_back(temp);
            }
            return;
        }
        
        if (candidates[start]<=target){
            temp.push_back(candidates[start]);
            combination(start, target-(candidates[start]), candidates, temp, res);
            temp.pop_back();
        }
         combination(start+1, target, candidates, temp, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        combination(0,target,candidates,temp,res);
        return res;
    }
};
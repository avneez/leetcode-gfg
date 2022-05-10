class Solution {
public:
    void combination(int start,int k,int n,vector<int> &temp, vector<vector<int>> &res){
        //if (k<0 || n<0) return;
        
        if (k==0 && n==0){
            res.push_back(temp);
            return;
        }
        for (int i=start; i<=9; i++){
            temp.push_back(i);
            combination(i+1,k-1,n-i,temp,res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> res;
        combination(1,k,n,temp,res);
        return res;
    }
};
class Solution {
public:
    bool checkRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (mat[i][j]!=target[i][j]) return false; 
            }
        }
    return true;
}

    void Rotation90(vector<vector<int>>&mat){
        int n = mat.size();
        reverse(mat.begin(), mat.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }   
    
     bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0;i<4; i++){
            Rotation90(mat);
            if(checkRotation(mat, target)) return true;
        }
        return false;       
    }
};
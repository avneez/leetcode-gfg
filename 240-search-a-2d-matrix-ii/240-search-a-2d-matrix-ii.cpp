class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int row=0, col=n-1;
        
        while(row<m and col>=0){
            if(target<matrix[row][col]) col--;
            else if(target>matrix[row][col]) row++;
            else return true;
        }
        return false;
    }
};
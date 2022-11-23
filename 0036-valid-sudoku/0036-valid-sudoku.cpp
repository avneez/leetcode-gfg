class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int k = (i/3)*3+j/3;
                    string row = "row"+to_string(i)+board[i][j];
                    string col = "col"+to_string(j)+board[i][j];
                    string box = "box"+to_string(k)+board[i][j];
                    if(seen.find(row)==seen.end() and seen.find(col)==seen.end() and seen.find(box)==seen.end()){
                        seen.insert(row);
                        seen.insert(col);
                        seen.insert(box);
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};
    
    
//     bool isSafe(vector<vector<char>>& board , int temp, int row, int col){
//         for(int i=0;i<board.size();i++)
//         {
//             if(board[row][i] == temp)
//             {
//                 return false;
//             }
//             if(board[i][col] == temp)
//             {
//                 return false;
//             }
//             if(board[row/3 *3 + i/3] [  col/3 * 3 +   (i%3)  ] == temp)
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
    
    
//     bool isValidSudoku(vector<vector<char>>& board) {
        
//         for(int i=0;i<board.size();i++)
//         {
//             for(int j=0;j<board.size();j++)
//             {
//                 if(board[i][j] != '.') {
//                     int temp = board[i][j];
//                     board[i][j]  = '*';
//                     if(!isSafe(board, temp, i ,j))
//                         return false;
//                     board[i][j] =  temp;
//                 }
                
//             }
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         int row[9][9] = {0}, col[9][9] = {0}, sub[9][9] = {0};
        
//         for(int i = 0; i < 9; i++) {
//             for(int j = 0; j < 9; j++)  {
//                 if(board[i][j] != '.')  {
//                     int num = board[i][j] - '1', k = i/3*3 + j/3;
//                     if(row[i][num] || col[j][num] || sub[k][num])
//                         return false;
//                     row[i][num] = col[j][num] = sub[k][num] = 1;
//                 }
//             }
//         }
//         return true;
//     }
// };
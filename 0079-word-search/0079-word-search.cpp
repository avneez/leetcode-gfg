class Solution {
public:
    bool dfs(int i, int j, int c, vector<vector<char>>& board, string word){
        int x[4] = {0,1,-1,0};
        int y[4] = {1,0,0,-1};
        
        int m = board.size();
        int n = board[0].size();
        
        if(c==word.size()) return true;
        if(i>=m or j>=n or i<0 or j<0 or board[i][j]!=word[c]) return false;
        
        char temp = board[i][j];
        board[i][j] = '1'; //mark visited
        
        bool ans;
        for(int d=0; d<4; d++){
            ans += dfs(i+x[d],j+y[d],c+1,board,word);
        }
        // int ans = dfs(i+1,j,c+1,board, word) or dfs(i-1,j,c+1,board, word) or dfs(i,j+1,c+1,board, word) or dfs(i,j-1,c+1,board, word);
        
        board[i][j]=temp;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0] and dfs(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
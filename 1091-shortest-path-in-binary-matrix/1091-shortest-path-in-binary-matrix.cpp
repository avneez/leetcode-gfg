class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j, int n, vector<vector<bool>>& visited){    
        return (i>=0 and i<n and j>=0 and j<n and grid[i][j]==0 and !visited[i][j]);
        }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 and n==1) return 1;
        
        vector<vector<int>> dir = {{0,1},{1,0},{1,1},{0,-1},{1,-1},{-1,-1},{-1,0},{-1,1}};
        
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<pair<int, int>,int>> q;
        q.push({{0,0},1});
        visited[0][0]=true;
               
        while(!q.empty()){
            auto p = q.front().first; //{0,0}
            int x = p.first;
            int y = p.second;
            int length = q.front().second; //1
            q.pop();
            
            for(int d=0; d<8; d++){
                int newx = x + dir[d][0];
                int newy = y + dir[d][1];
                
                if(isValid(grid,newx,newy,n,visited)){
                    q.push({{newx,newy},length+1});
                    visited[newx][newy]=true;
                    if(newx==n-1 and newy==n-1)
                        return length+1;
                }
            }
            
        }
        return -1;
        
    }
};
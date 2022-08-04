class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        int ans=0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
        //bfs
        minh.push({0,0,0});
        while(minh.size()){
            auto res=minh.top();
            minh.pop();
            ans=max(ans,res[0]); //update ans
            
            int i=res[1]; int j=res[2];
            //conditions
            if(heights[i][j]==-1)  //already visited
                continue;
            if(i==m-1 and j==n-1)  //reached last cell
                break;
            
            //checking for new directions
            for(int d=0; d<4; d++){
                int newi = i+dir[d][0];
                int newj = j+dir[d][1];
                if(newi<0 || newj<0 || newi==m || newj==n || heights[newi][newj]==-1)
                    continue;
                
                minh.push({abs(heights[i][j]-heights[newi][newj]),newi,newj}); //push effort and posn
            }
            heights[i][j]=-1;
        }
        return ans;
    }
};
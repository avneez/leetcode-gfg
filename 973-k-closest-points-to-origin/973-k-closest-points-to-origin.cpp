class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> maxh;
        for(int i=0; i<points.size(); i++){
            int x=points[i][0];
            int y=points[i][1];
            int dist=(x*x+y*y);
            maxh.push({dist,i});
            if(maxh.size()>k) maxh.pop();
        }
        vector<vector<int>> ans;
        while(!maxh.empty()){
            int pointIndex = maxh.top().second;
            ans.push_back(points[pointIndex]);
            maxh.pop();
        }
        return ans;
    }
};
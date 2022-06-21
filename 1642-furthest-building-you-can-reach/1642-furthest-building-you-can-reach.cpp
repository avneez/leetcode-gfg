class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> mh;
        int diff=0, brickSum=0;
        for(int i=1; i<n; i++){
            diff = heights[i]-heights[i-1];
            if(diff<=0) continue;
            mh.push(diff);
            
            if(mh.size() > ladders){
                brickSum+=mh.top();
                mh.pop();
            }
            if(brickSum>bricks) return i-1;
        }
        return n-1;
    }
};
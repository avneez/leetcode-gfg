class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        
        priority_queue<pair<int,int>> maxh;
        for(int i=0; i<arr.size(); i++){
            maxh.push({abs(arr[i]-x), arr[i]});
            if(maxh.size()>k) maxh.pop();
        }
        while(maxh.size()>0){
            int x = maxh.top().second;
            ans.push_back(x);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
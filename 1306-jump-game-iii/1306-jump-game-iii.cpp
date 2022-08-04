class Solution {
public:
    bool helper(vector<int>& arr, int start, vector<bool>& visited){
        if(start<0 || start>=arr.size() || visited[start]==true){
            return false;
        }
        visited[start]=true;
        if(arr[start]==0) return true;
        bool x=helper(arr, start+arr[start], visited);
        bool y=helper(arr, start-arr[start], visited);
        return x||y;
        
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size()+1, false);
        return helper(arr,start, visited);
    }
};

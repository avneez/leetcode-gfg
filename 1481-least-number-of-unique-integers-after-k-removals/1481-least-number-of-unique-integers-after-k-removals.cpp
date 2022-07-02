class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        
        for(auto i:arr)
            mp[i]++;
        
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto it:mp) 
            q.push(it.second);
        
        int n=mp.size();
        while(!q.empty() and k>0){
            int x = q.top();
            q.pop();
            if(x<=k){
                k-=x;
                n--;
            }
            else break;
        }
        return n;
    }
};

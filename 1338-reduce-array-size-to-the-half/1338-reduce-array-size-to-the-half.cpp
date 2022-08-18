class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int> mp;
        for(auto it:arr){
            mp[it]++;
        }
        multimap<int,int,greater<int>> mpp;
        for(auto it:mp){
            mpp.insert({it.second,it.first});
        }
        
        int n=arr.size();
        n=n/2; int c=0;
        for(auto i:mpp){
            n-=i.first;
            c++;
            if(n<=0) break;
        }
        return c;
    }
};
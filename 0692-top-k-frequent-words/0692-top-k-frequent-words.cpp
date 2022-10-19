class Solution {
public:
    bool static compare(pair<int,string> p1, pair<int,string> p2){
        if(p1.first==p2.first) return p2.second>p1.second;
        return p1.first>p2.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto it:words) mp[it]++;
        
        vector<pair<int,string>> v;
        for(auto i:mp){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(), compare);
        vector<string> ans;
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
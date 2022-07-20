class Solution {
public:
    bool check(string s1, string s2){
        int i = 0, j = 0;
        while(i<s1.size() and j<s2.size()){
            if(s1[i] == s2[j]) i++;
            j++;
        }
        if(i == s1.size()) return true;
        return false;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string, int> m;
        for(auto x : words) m[x]++;
        
        for(auto x : m){
            if(check(x.first,s))
                ans+=x.second;
        }
        return ans;
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s(words.begin(), words.end());     
        
        for(auto it:s){
            int n=it.size();
            for(int i=1; i<n; i++){
                string str = it.substr(i,n);
                
                if(s.find(str)!=s.end())
                    s.erase(str);
            }
        }
        int ans=0;
        for(auto it:s){
            ans+=it.size()+1;
        }
        return ans;
    }
};

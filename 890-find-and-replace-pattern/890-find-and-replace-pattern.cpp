class Solution {
public:
    vector<int> found_pattern(string pattern){
        vector<int> v;
        int ind=0;
        
        unordered_map<char,int> mp;
        for(int i=0; i<pattern.size(); i++){
            if(mp.find(pattern[i])==mp.end()){
                mp.insert({pattern[i],ind++});
                v.push_back(mp[pattern[i]]);
            }
            else{
                v.push_back(mp[pattern[i]]);
            }
        }
        return v;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<int> v2 = found_pattern(pattern); 
        
        for(int i=0; i<words.size(); i++){
            vector<int> word_pattern = found_pattern(words[i]);
            if(v2==word_pattern){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
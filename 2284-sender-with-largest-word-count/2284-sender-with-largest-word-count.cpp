class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>> mx;
        
        for(int i=0; i<messages.size(); i++){
            mp[senders[i]]++;
            string s=messages[i];
            for(int j=0; j<s.size(); j++){
               if(s[j]==' ')
                   mp[senders[i]]++;
            }
        }
        for(auto it:mp){
            mx.push({it.second,it.first});
        }
        return mx.top().second;
    }
};
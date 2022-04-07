class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         //if (strs.length ==0) return "";
        string prefix = strs[0];
        for (int i=1; i<strs.size(); i++){
            while(strs[i].find(prefix)!=0){
                prefix = prefix.substr(0, prefix.size()-1);
            }
        }
        return prefix;
    }
};

//prefix = flower (--) until fl
//["flow", "flight"]
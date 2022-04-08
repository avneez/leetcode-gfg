class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        for(int i=0;i<n;i+=k){
            string div = s.substr(i,k);
            int j = s.substr(i,k).size();
            if(j<k){
                int lengthRem = s.substr(i,n).size();
                int t = k-lengthRem;
                string temp = s.substr(i,n);
                while(t--){
                    temp+=fill;
                }
                ans.push_back(temp);
            }
            else ans.push_back(div);
        }
        return ans;
    }
};
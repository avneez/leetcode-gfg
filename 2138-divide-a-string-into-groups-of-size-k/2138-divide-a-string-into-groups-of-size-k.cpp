class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        string temp="";
        int x=n%k;
        if(x!=0){
            for(int i=0;i<k-x;i++) 
                s+=fill;
        }
        
        for(int i=0;i<s.size();i=i+k){
            temp=s.substr(i,k);
            ans.push_back(temp);  
        }    
        return ans;
    }
};
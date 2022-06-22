class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int m=s.size();
        int n=t.size();
        
        
        while(i<m && j<n)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
            
        }
        cout<<i<<" "; 
        
        if(i==m)
            return true;
        else
            return false;
    }
};
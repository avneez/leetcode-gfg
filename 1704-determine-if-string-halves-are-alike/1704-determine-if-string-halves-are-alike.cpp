class Solution {
public:
    bool isVow(char c){
        return c=='a' || c=='A' || c=='e' || c=='E' || c=='i' || c=='I' || c=='o' || c=='O' || c=='u' || c=='U';
    }
    
    bool halvesAreAlike(string s) {
        int n = s.size();
        int l=0, r=n-1, c1=0,c2=0;
        
        for(int i=0; i<n/2; i++){
            if(isVow(s[l++])) c1++;
            if(isVow(s[r--])) c2++;
        }
        if(c1==c2) return true;
        return false;
    }
};
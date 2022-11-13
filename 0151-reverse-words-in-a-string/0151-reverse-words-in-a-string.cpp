class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int l = 0;
        int r = 0;
        int idx = 0;
        
        while(idx<n){
            bool isWord = false;
            while(idx<n && s[idx]!=' '){
                s[r] = s[idx];
                r++;
                idx++;
                isWord = true;
            }
            // s[idx] must be ' '
            if(isWord){
                reverse(s.begin()+l, s.begin()+r);
                s[r++] = ' ';       // add space to seperate
                l = r;
            }
            
            // since s[idx] is ' ' we need to pass it
            idx++;
        }
        
        //to escape the last ' '
        s.resize(r-1);
        return s;
    }
};
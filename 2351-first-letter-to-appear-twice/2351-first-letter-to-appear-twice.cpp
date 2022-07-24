class Solution {
public:
    char repeatedCharacter(string s) {
        set<char> st;
        for(char c:s){
            if(st.count(c)==1) return c;
            st.insert(c);
        }
        return ' ';
    }
};
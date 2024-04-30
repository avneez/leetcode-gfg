class Solution {  
public:
     bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    };
    
    int countVowelSubstrings(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp.clear();
            for (int j = i; j < s.size() && isVowel(s[j]); j++) {
                mp[s[j]]++;
                if (mp.size() == 5) ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'I' || c ==                 'E' || c == 'O' || c == 'U';
    }
    
    string reverseVowels(string s) {
       int i=0, j=s.size()-1;
        while(i<j){
            // Find the leftmost vowel
            while (i < s.size() && !isVowel(s[i])) {
                i++;
            }
            // Find the rightmost vowel
            while (j >= 0 && !isVowel(s[j])) {
                j--;
            }
            // Swap them if start is left of end
            if (i<j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
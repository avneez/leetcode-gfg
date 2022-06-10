class Solution {
public:        
    int lengthOfLongestSubstring(string s) {        
        unordered_map<char, int> freq;        
        int n = s.length(), st = 0, end = 0, ans = 0;		
        while(end < n){            
            freq[s[end]]++;   
            // As soon as frequency of any character becomes more than one, contract window till frequency of               that character reduces to 1.
            while(freq[s[end]] != 1){
                freq[s[st]]--;
                st++;
            }    
            // Update ans at each end index.
            ans = max(ans, end - st + 1);
            end++;                   
        }        
        return ans;        
    }
};



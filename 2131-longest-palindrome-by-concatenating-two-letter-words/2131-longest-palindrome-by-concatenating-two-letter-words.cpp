class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        int ans = 0;
        
        for (auto w : words) {
            int a = w[0] - 'a';
            int b = w[1] - 'a';
            
            if (count[b][a]>0) {
                ans += 4;
                count[b][a]--; // decrement the count as we found mirror word
            } else {
                count[a][b]++; // increment the current word if we not find any mirror
            }
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i][i]) {  // Both are same characters
                ans += 2;
                break;
            }
        }
        return ans;
    }
};

//   int res = 0;
//        unordered_map<string,int> hm; 
       
//        for(string s:words){ // match to make pairs that can be taken in palindrome
//            string p = s;
//            reverse(p.begin(),p.end());
//            if(hm[p]>0){ // reverse of current string found, these 2 strings can be added to palindrome 
//                res+= 4;
//                hm[p]--;  // remove occurence of string as we used it for palindrome
//            }
//            else{
//                hm[s]++;   // reverse not fount , put it in hashmap
//            }
//        }
//          //***** to take element at the center with both letters same
//        for(auto i:hm){   // only strings with frequency 1 are left now  
//            if(i.first[0]==i.first[1] && i.second>0){ // to place in center of palindrome we needs chars to be same
//                return res+2;   
//            }
//        }

//        return res;
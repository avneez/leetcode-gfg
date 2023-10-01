// class Solution {
// public:
//     string reverseWords(string s) {
//         string temp, ans;
//         vector<string> v;
        
//         for(int i=0; i<s.size(); i++){
//             if(s[i]==' ' or i == (s.size() - 1)){
//                 // reverse(temp.begin(), temp.end());
//                 // ans+=temp;
//                 v.push_back(temp);
//                 temp=" ";
//             }
//             else temp+=s[i];
//         }
//         reverse(temp.begin(),temp.end());
//         // ans+=temp;
//         v.push_back(temp);

        
//         for(int i=0; i<v.size(); i++){
//             string temp2=v[i];
//             reverse(temp2.begin(),temp2.end());
//             ans+=temp2;
//             if(i!=v.size()-1) ans+=' ';
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     string reverseWords(string s)
//     {
//         int i=0;
        
//           for(int j=0; j<s.size(); j++)
//           {
//               if(s[j] == ' ')
//               {
//                   reverse(s.begin()+i, s.begin()+j);
//                   i = j+1;
//               }
//           }
        
//         reverse(s.begin()+i,s.end());
        
//         return s;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string t, ans;
        
        while (getline(ss, t, ' ')) {
            reverse(t.begin(), t.end());
            ans += t + ' ';
        }
        // We will take substring of one less size as there will be space after last word which is not required.
        return ans.substr(0, ans.size() - 1); 
    }
};
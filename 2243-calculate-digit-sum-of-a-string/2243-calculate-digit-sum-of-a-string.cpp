class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k) {
            string temp=""; 
            for(int i=0; i<s.size(); i=i+k){
                int sum=0;
                for(int j=0; j<k; j++) {
                    if(i+j >= s.size())
                        break;
                    sum+= s[i+j]-'0'; 
                }
                temp+= to_string(sum);
            }
            s=temp;
        }
        return s;
    }
};
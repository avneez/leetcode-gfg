class Solution {
public:
    vector<string> ans;
    void generate(string str, int open, int close){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open>0){
            str.push_back('(');
            generate(str,open-1,close);
            str.pop_back();
        }
        
        if(close>0){
            if(open<close){  //in str more open has been used so for next str, we have less open than close 
                str.push_back(')');
                generate(str,open,close-1);
                str.pop_back();
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string str;
        generate(str,n,n);
        return ans;
    }
};
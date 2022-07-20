class Solution {
public:
    void fun(string digits,vector<string> str,vector<string> &ans,int n,int i,string temp){
        // if(i>n) return ;
        if(i>=n){
            ans.push_back(temp);
            return ;
         }
        string value = str[(digits[i]-'0')];
        for(char s : value)
            fun(digits,str,ans,n,i+1,temp+s);
        // temp.pop_back();  //backtrack without this line also running in adv for loop
        }
        
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> str,ans;
        // string temp="";
        str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n=digits.size();
        fun(digits,str,ans,n,0,""); //Empty string "" is our temp in rec func
        return ans;
    }
};
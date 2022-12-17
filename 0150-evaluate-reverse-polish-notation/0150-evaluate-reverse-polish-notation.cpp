class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto &t:tokens){
            if(t!="+" && t!="-" && t!="/" && t!="*"){
                stk.push(stoi(t));
                continue;
            }
            else{
                long long ftop=stk.top();
                stk.pop();
                long long stop=stk.top();
                stk.pop();
                if(t=="+") stk.push(stop+ftop);
                
                else if(t=="-") stk.push(stop-ftop);
        
                else if(t=="*") stk.push(stop*ftop);
                
                else stk.push(stop/ftop);
            }
        }
        return stk.top();
    }
};
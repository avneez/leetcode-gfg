class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans=0;
        stack<int> st;
        // unordered_map<string, int> mp={{"C",1}, {"D",2}, {"+",3}};
        
        for (int i=0; i<ops.size(); i++){
            // if(mp[ops[i]]!=1 && mp[ops[i]]!=2 && mp[ops[i]]!=3){
            //    int x = stoi(ops[i]);
            //     st.push(x);
            // }  
            if(ops[i]=="C")
                    st.pop();
            else if(ops[i]=="D")
                    st.push(st.top()*2);
            else if(ops[i]=="+")
            {
                int temp=st.top();
                st.pop();
                int a=temp+st.top();
                st.push(temp);
                st.push(a);
            }
            else
            {
                st.push(stoi(ops[i]));
            }
                    
        }
        while (!st.empty()){
            ans+=st.top();
            cout<<st.top()<< " ";
            st.pop();
        }
        
        return ans;
    }
};
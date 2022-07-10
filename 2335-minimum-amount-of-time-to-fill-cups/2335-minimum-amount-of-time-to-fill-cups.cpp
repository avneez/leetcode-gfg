class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sec =0;

        priority_queue<int> q;
        for(auto i:amount) q.push(i);
        
        while(q.top()!=0){
            int a=q.top(); q.pop();
            int b=q.top(); q.pop();
            int c=q.top(); q.pop();
            
            if(b!=0){
                sec++;
                b-=1;
                a-=1;
                q.push(b);
                q.push(a);
                q.push(c);
            }
            else{
                sec+=a;
                a=0;
            }           
        }
       return sec;
    }
        
        // int mx = 0, sum = 0;
        // for(int& a: amount) {
        //     mx = max(a, mx);
        //     sum += a;
        // }
        // return max(mx, (sum + 1) / 2);
        // }
};
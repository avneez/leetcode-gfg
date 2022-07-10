class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sec =0;
        sort(amount.begin(), amount.end());
        if(amount[0]+amount[1]>amount[2]){
            int s= amount[0]+amount[1]+amount[2];
           return s/2+s%2;
        }
        else return amount[2];
    }
        
        // int mx = 0, sum = 0;
        // for(int& a: amount) {
        //     mx = max(a, mx);
        //     sum += a;
        // }
        // return max(mx, (sum + 1) / 2);
        // }
};
#define min(a,b)(a<b ? a:b)

class Solution {
    int mod=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        // vector<int> dp(n+1,0);
        // long long sum=0;
        // long long mini=INT_MAX;
        // for(int i=0;i < n;i++){
        //    	mini=arr[i];
        //     sum+=mini;
        //     for(int j=i+1;j < n;j++){
        //    	    mini=min(mini,arr[j]);
        //    	    sum+=mini;
        //     }           
        // }
        // return (sum%mod);
        
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= arr.size(); i++){
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])){
                int idx = st.top();
                st.pop();
                long right = i < n ? i - idx : n - idx;
                long left = st.empty() ? idx + 1 : idx - st.top();
                ans = (ans + left *right *arr[idx]) % mod;
            }
            st.push(i);
        }
        return ans;
    }
};
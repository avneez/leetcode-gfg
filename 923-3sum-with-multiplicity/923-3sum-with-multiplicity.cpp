class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, long>mp;
        int mod = 1e9+7;
        for (int x: arr) mp[x]++;
        long res = 0;
        for(auto it: mp)
            for (auto it2: mp){
                int i = it.first, j = it2.first, k = target-i-j;
                if (!mp.count(k)) continue;
                if (i==j && j==k) 
                    res+= mp[i] * (mp[i]-1) * (mp[i]-2)/6;
                else if(i==j && j!=k)
                    res+= mp[i] * (mp[i]-1)/2 * mp[k];
                else if (i<j && j<k)
                    res += mp[i]*mp[j]*mp[k];
            }
        return res%mod;
    }
};
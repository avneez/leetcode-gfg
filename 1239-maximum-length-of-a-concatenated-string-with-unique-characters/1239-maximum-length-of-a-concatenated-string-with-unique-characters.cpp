class Solution {
public:
    int maxi=INT_MIN;
    bool unique(string s){
        vector<int> mp(26,0);
        for(int i=0; i<s.size(); i++){
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']>1)
                return false;
        }     
        return true;
    }
    
    void fun(vector<string>&arr, int i, int n, string curr){
        if(!unique(curr)) return;
        if(i==n){
            int size=curr.size();
            if(size>maxi){
                maxi=max(size,maxi);
            }
            return;
        }
        fun(arr,i+1,n,curr+arr[i]); //include string
        fun(arr,i+1,n,curr);        //exclude string
    }
    
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        fun(arr,0,n,"");
        return maxi;
    }
};
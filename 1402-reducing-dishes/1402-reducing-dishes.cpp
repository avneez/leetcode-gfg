class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        
        vector<int> psum=satisfaction;
        
        for(int i=1;i<n;i++){
            psum[i]+=psum[i-1];
        }
        
        int maxi=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=psum[i];
            maxi=max(cur,maxi);
        }
        return maxi;
    }
};
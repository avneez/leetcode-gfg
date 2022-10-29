class Solution {
public:

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        int comp=0, pt=0;
        if(n==1) return plantTime[0]+growTime[0];
        
        vector<pair<int,int>> vg;
        for(int i=0; i<n; i++){
            vg.push_back({growTime[i],plantTime[i]});
        }
        sort(vg.begin(),vg.end(),greater<pair<int,int>>());
        for(int i=0; i<n; i++){
            pt+=vg[i].second;
            comp= max(comp,pt+vg[i].first); 
        }
        return comp;
    }
};
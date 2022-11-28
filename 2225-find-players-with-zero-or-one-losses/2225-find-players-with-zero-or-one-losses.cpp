class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        vector<vector<int>> v(2, vector<int>());
        // map<int,int> mpw;
        map<int,int> mpl;
        
        for(int i =0; i<n; i++){
            int w = matches[i][0];
            int l = matches[i][1];
            // mpw[w]++;
            if(mpl.find(w)==mpl.end()){
                mpl[w]=0;
            }
            mpl[l]++;
        }
      
        for(auto it:mpl){
            if(it.second==1){
                v[1].push_back(it.first);
            }
            else if(it.second==0){
                v[0].push_back(it.first);
            }
        }
        return v;
    }
};
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int m=img1.size();
        int n=img2.size();
        
        vector<pair<int, int>> v1, v2;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(img1[i][j]) v1.push_back({i, j});
                if(img2[i][j]) v2.push_back({i, j});
            }
        }
        
        map<pair<int, int>, int> translate; 
        int maxi = 0;
        
        for(auto i : v1){
            for(auto j : v2){
                int x = j.first - i.first;
                int y = j.second - i.second;
                translate[{x, y}]++;
                maxi = max(maxi, translate[{x, y}]);
            }
        }
        return maxi;
    }
};
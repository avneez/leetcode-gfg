// class Solution {
// public:
//     vector<vector<int>> findWinners(vector<vector<int>>& matches) {
//         int n = matches.size();
//         vector<vector<int>> v(2, vector<int>());
//         // map<int,int> mpw;
//         map<int,int> mpl;
        
//         for(int i =0; i<n; i++){
//             int w = matches[i][0];
//             int l = matches[i][1];
//             // mpw[w]++;
//             if(mpl.find(w)==mpl.end()){
//                 mpl[w]=0;
//             }
//             mpl[l]++;
//         }
      
//         for(auto it:mpl){
//             if(it.second==1){
//                 v[1].push_back(it.first);
//             }
//             else if(it.second==0){
//                 v[0].push_back(it.first);
//             }
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> lossesCount(100001, -1);

        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            if (lossesCount[winner] == -1) {
                lossesCount[winner] = 0;
            }
            if (lossesCount[loser] == -1) {
                lossesCount[loser] = 1;
            } else {
                lossesCount[loser]++;
            }
        }

        vector<vector<int>> answer(2, vector<int>());
        for (int i = 1; i < 100001; ++i) {
            if (lossesCount[i] == 0) {
                answer[0].push_back(i);
            } else if (lossesCount[i] == 1) {
                answer[1].push_back(i);
            }
        }

        return answer;
    }
};
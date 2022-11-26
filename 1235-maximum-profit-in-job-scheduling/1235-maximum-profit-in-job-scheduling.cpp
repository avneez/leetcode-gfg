// Consider using dp, define dp[i] := the maximum profit we can get from the first i jobs with smallest endTime.
// Then we should first generate an index array: index, such that endTime[index[i]] <= endTime[index[i+1]] for 0 <= i < n-1, where n is the length of endTime.
// Then the recurrence relation:
// dp[i] = max(dp[i-1], profit[index[i-1]] + dp[j]),
// where j is the largest int such that endTime[index[j-1]] <= startTime[index[i-1]].
// we use binary search to find j here.


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
 
        auto comp = [&endTime](const int i1, const int i2) { 
            return endTime[i1] < endTime[i2]; 
        };
        
        int n = endTime.size();
        vector<int> index(n);
        iota(index.begin(), index.end(), 0);   //create index array from 0 to n-1
        sort(index.begin(), index.end(), comp);
        
        vector<int> endSorted(endTime.begin(), endTime.end());
        sort(endSorted.begin(), endSorted.end());
        
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            int j = upper_bound(endSorted.begin(), endSorted.end(), startTime[index[i-1]]) - endSorted.begin();
            dp[i] = max(dp[i-1], profit[index[i-1]] + dp[j]);
        }
        return dp[n];
    }
};
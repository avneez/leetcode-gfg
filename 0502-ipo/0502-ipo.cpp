class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        
        priority_queue<int> maxh;
        int j = 0;
        for (int i = 0; i < k; i++) {
            while (j < n && projects[j].first <= w) {
                maxh.push(projects[j++].second);
            }
            if (maxh.empty()) {
                break;
            }
            w += maxh.top();
            maxh.pop();
        }
        return w;
    }
};
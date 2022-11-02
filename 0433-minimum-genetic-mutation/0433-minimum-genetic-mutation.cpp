class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_map<string, int> vis;
        int steps = 0;
 
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            // n = q.size();
            // for (int i = 0; i < n; i++) { 
            for (int i = q.size(); i > 0; i--) {
                string s = q.front();
                q.pop();
                // if it is same as `end`, that means we found the answer
                if (s == end) return steps;
                // otherwise, given a gene string with 8-character long
                // we can replace each character with "A", "C", "G" and "T" (i.e. mutate)
                for (int j = 0; j < 8; j++) {
                    // s[j] will be modified later, 
                    // hence store the original character here
                    char oc = s[j];
                    // iterate ACGT
                    // alternatively, you can use `for (char c : "ACGT") { ... }`
                    for (int k = 0; k < 4; k++) {
                        // replace the j-th character in s with the k-th character in ACGT
                        s[j] = "ACGT"[k];
                        // we can reach the next node if the next node hasn't been visited
                        // and the next node is available in `bank`
                        if (!vis[s] && find(bank.begin(), bank.end(), s) != bank.end()) {
                            // push the next node to the queue
                            q.push(s);
                            vis[s] = 1;
                        }
                    }
                    // since we updated the character, we revert it back
                    s[j] = oc;
                }
            }
            steps += 1;
        }
        return -1;
    }
};


    // Intuition: we can see each string as a node and we can connect them if 
    // 1. there is only one single character different
    // 2. the target node is available in `bank`
    // the problem is now to find the shortest path from the starting point to the ending point
    // so we can use BFS
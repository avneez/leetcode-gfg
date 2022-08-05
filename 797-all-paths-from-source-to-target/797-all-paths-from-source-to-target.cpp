class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<int>& path, int source, vector<vector<int>> &ans)  {
        path.push_back(source);
        if(source==graph.size()-1){
            ans.push_back(path);
        }
        else{
            for(auto it: graph[source]){
                dfs(graph, path, it, ans);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(graph, path, 0, ans);
        return ans;
    }
};
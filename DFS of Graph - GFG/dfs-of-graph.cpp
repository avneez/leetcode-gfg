// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
     void DFSUtil(int s, vector<int> adj[], bool visited[], vector<int> &res){
	    if(visited[s]) return;
	    visited[s] = true;
	    res.push_back(s);
	    for (int u : adj[s]){
	        if (!visited[u])
	            DFSUtil(u, adj, visited, res);
	    }
     }   
	vector<int> dfsOfGraph(int V, vector<int> adj[]){
	    bool visited[V];
	    memset(visited, false, sizeof(visited));
	    int s;
	    vector <int> res;
	   // for (int i = 0; i < V; i++)
	   //     if (!visited[i]){
	   //         DFSUtil (i, adj, visited, res);
	   //     }
	    DFSUtil(s,adj,visited,res);
	    return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
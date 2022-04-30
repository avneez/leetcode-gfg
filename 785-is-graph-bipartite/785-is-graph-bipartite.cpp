class Solution {
public:
    
   bool isBipartite(vector<vector<int>>& graph){ 
        int n=graph.size();
        vector<int> color(n,0);    
        for(int i=0;i<n;i++){                // traverse each component
            if(color[i]) continue;          // if already coloured then continue
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int parent=q.front();
                q.pop();
                for(int child:graph[parent]){
                    if(color[child]==0){
                        color[child]=-color[parent];
                        q.push(child);
                    }
                    else{
                        if(color[parent]==color[child]) return false;    
                        // if parent and child have same colour then return false;
                    }
                }
            }
        }
        return true;
    }
};
//     bool isBipartiteDFS(vector<vector<int>>& graph, int color[], int node){
//         if (color[node]==-1) color[node]=1;
        
//         for (auto it: graph[node]){
//             if(color[it]==-1){
//                 color[it]=1-color[node];
//                 if(!isBipartiteDFS(graph, color, it)) 
//                     return false;
//                 else if(color[it]==color[node]) 
//                     return false;
//             }
//         }
//         return true;     
//     }
    
//     bool isBipartite(vector<vector<int>>& graph){
//         int n = graph.size();
//         int color[n];
//         memset(color, -1, sizeof(color));
        
//         for(int i = 0; i < n; i++){ 
//             if(color[i] == -1){
//                 if(!isBipartiteDFS(graph, color, i)) 
//                     return false;
//             }    
//         }
//         return true;
//     }
// };
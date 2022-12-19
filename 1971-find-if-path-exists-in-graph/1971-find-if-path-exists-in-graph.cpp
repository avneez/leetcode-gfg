class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int,vector<int>> path;
        for(auto& it:edges){          //bidirectional path, record all destinations from all nodes
            path[it[0]].push_back(it[1]);
            path[it[1]].push_back(it[0]);
        }
        queue<int> q;
        vector<bool> vis(n,false);
        q.push(start);
        while(!q.empty()){
            int cur=q.front(); q.pop();
            if(cur==end) return true;
            for(auto& i:path[cur]){
                if(!vis[i]){
                    q.push(i);
                    vis[i]=true;
                }
            }
        }
        return false;
    }
};

//0->1,2; 1->2,0; 2->1,0;

//0->1,2
//1->0,
//2->0,   //disconnected component, we never reached to 5 from 0
//3->5,4
//4->5,3,
//5->3,4,
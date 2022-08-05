class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 0;
        
        unordered_map<int, vector<int>> indices;
        for(int i=0; i<n; i++){
            indices[arr[i]].push_back(i);
        }
        
        vector<bool> vis(n); 
        vis[0]=true;
        queue<int> q;
        q.push(0);
        int step=0;
        while(!q.empty()){
            int size = q.size();
            for(int k=0; k<size; k++){
                int i=q.front(); q.pop();
                if(i==n-1)
                    return step; //reached last index
                
                vector<int>& next=indices[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(int j:next){
                    if(j>=0 && j<n && !vis[j]){
                        vis[j]=true;
                        q.push(j);
                    }
                }
                indices[arr[i]].clear();
            }
            step++;
        }
        return -1;
    }
};

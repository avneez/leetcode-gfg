class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        int n = stones.size();
        
        for(int i=0; i<n; i++){
            maxHeap.push(stones[i]);
        }
        int max,smax;
        while(n>1){
            max = maxHeap.top();
            maxHeap.pop();
            smax = maxHeap.top();
            maxHeap.pop();
            n-=2; //two less stones now
            
            if(max-smax>0){
                maxHeap.push(max-smax);
                n+=1; // 1 resultant weight stone added
            }
        }
        if (!maxHeap.empty()) return maxHeap.top();
        return 0;        
    }
};
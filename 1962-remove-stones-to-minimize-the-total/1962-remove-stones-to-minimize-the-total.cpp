class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> heap(piles.begin(), piles.end());
        int totalSum = 0;
        for(auto &i: piles) totalSum+=i;
        
        for (int i = 0; i < k; i++) {
            int curr = heap.top();
            heap.pop();
            int remove = curr / 2;
            totalSum -= remove;
            heap.push(curr - remove);
        }
        
        return totalSum;
    }
};
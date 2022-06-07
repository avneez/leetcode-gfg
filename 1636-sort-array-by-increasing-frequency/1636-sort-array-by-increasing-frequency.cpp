class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        priority_queue <pair <int,int>> q;
        for(auto &i:mp){
            q.push({-i.second,i.first});
        }
        nums.clear();
        while(!q.empty()){
            int freq = -1*q.top().first;
            int elem = q.top().second;
            for(int i=0; i<freq; i++){
                nums.push_back(elem);
            }
            q.pop();
        }
        return nums;
    }
};
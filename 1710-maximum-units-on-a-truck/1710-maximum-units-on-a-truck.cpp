class Solution {
public:
    bool static comp(vector<int> a, vector<int> b){
        return a[1]>b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), comp);
        
        int tsum=0; int boxes =0;
        for(auto box: boxTypes){
            
            int boxes = min(truckSize, box[0]);
            tsum += boxes*box[1];
            truckSize -= boxes;
        }
        return tsum;
    }
};

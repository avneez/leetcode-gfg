class Solution {
public:
    
    //using MaxHeap
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//         vector<int> ans;
        
//         priority_queue<pair<int,int>> maxh;
//         for(int i=0; i<arr.size(); i++){
//             maxh.push({abs(arr[i]-x), arr[i]});
//             if(maxh.size()>k) maxh.pop();
//         }
//         while(maxh.size()>0){
//             int x = maxh.top().second;
//             ans.push_back(x);
//             maxh.pop();
//         }
//         sort(ans.begin(),ans.end());
//         return ans;
//     }
    
    //binary search approach
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0, r=arr.size()-k;
        vector<int>ans;
        while(l<r){
            int mid =(l+r)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                l=mid+1;
            }
            else{
                r=mid; 
            }   
        }
        
        for(int i=l;i<l+k;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};


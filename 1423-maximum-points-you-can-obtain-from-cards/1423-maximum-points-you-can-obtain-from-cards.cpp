class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
		
		//First k elements in our window
        for(int i=0;i<k;i++) res+=cardPoints[i];
        
        int curr=res;
        for(int i=k-1;i>=0;i--) {
			//We remove the last visited element and add the non-visited element from the last
            curr-=cardPoints[i];
            curr+=cardPoints[cardPoints.size()-k+i];
			res = max(res, curr);
        }
        
        return res;
    }
        
        
    //     int n = cardPoints.size();
    //     int l = 0,r = (n-k),total = 0,sum=0;
    //     for(int i=0;i<r;i++) sum+=cardPoints[i],total+=cardPoints[i];
    //     int  minSum = sum;
    //     while(r<n){
    //         sum+= (cardPoints[r]-cardPoints[l]);
    //         total+= cardPoints[r];
    //         l++,r++;
    //         minSum = min(minSum,sum);   
    //     }
    //    return total-minSum;
    // }
};
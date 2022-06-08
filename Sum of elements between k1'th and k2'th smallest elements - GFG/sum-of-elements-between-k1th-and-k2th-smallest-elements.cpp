// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    // long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
    //     sort(A,A+N);
    //     long long sum =0;
    //     for(int i = K1; i<K2-1; i++)
    //       sum += A[i];
    //   return sum;
    
    //Using maxHeap
    long long kthElement(long long A[], long long N, long long K){
       priority_queue<int> pq;
       for(int i = 0 ; i < N ; i++){
           pq.push(A[i]);
           if(pq.size() > K) pq.pop();
       }
       return pq.top();
   }
   
   
   long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
       // Your code goes here
       long long first = kthElement(A, N, K1);
       long long second = kthElement(A, N, K2);
       long long sum = 0;
       for(int i = 0 ; i < N ; i++){
           if(A[i] > first && A[i] < second){
               sum += A[i];
           }
       }
       return sum;
    }
};

// { Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    }
	return 0;
}
  // } Driver Code Ends
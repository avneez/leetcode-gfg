class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if( k == 0 ) return result;
        
        else if( k > 0 ){
            for( int index = 0 ; index<n; index++ ){
                int i = 1;
                int temp = 0;
                while( i <= k ){
                    temp += code[(index+i)%n];
                    i++;
                }
                result[index] = temp;
            }
        }
        else if( k < 0 ){
            k*=-1;
            for( int index = n-1; index >= 0 ; index-- ){
                int i = 1;
                int temp = 0;
                while( i <= (k)){
                    int j = index-i;
                    if( j < 0 ) j+=n;
                    temp +=code[j];
                    i++;
                }
                result[index] = temp;
            }
        }
        return result;
    }
};    
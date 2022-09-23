// class Solution {
// public:
    
//     int numberOfBits(int n) {
// 		  return log2(n) + 1;
//     }
    
//     int concatenatedBinary(int n) {
//         long ans = 0, MOD = 1e9 + 7;
        
//         for (int i = 1; i <= n; ++i) {
//             int len = numberOfBits(i);
//             ans = ((ans << len) % MOD + i) % MOD;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int concatenatedBinary(int n) {
        // `l` is the bit length to be shifted
        int M = 1e9 + 7, l = 0;
        long ans = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) l += 1;
            // (ans << l) means shifting the orginal answer `l` bits to th left
            // (x | i) means  using OR operation to set the bit
            ans = ((ans << l) | i) % M;
        }
        return ans;
    }
};
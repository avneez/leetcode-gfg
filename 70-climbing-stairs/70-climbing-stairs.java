class Solution {
    public int climbStairs(int n) {
        int memo[] = new int[Math.max(2,n)];
        memo[0]=1;
        memo[1]=2;
        if (n<=2) return n;
        
        for (int i=2; i<n; i++){
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n-1];        
    }
}
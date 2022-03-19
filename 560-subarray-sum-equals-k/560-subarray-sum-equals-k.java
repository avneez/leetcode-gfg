class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> map = new HashMap<>();
        int n = nums.length;
        if (n==0) return 0;
        int sum = 0; 
        int count = 0;
        int i=0;
        
        while(i<n){
         sum += nums[i];
            if (sum==k) count+=1;
            if (map.containsKey(sum-k)) count+=map.get(sum-k);
            
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            i++;
        }
        return count;
    }
}         
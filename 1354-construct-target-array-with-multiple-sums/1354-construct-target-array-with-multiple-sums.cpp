class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        priority_queue<int> pq;
        long long sum = 0;

        for(auto num : target){
            pq.push(num);
            sum+=num;
        }
     
        while(pq.top() != 1){

            sum -= pq.top(); //removing the greatest element as it was last upadted when converting [1,1,1...]                                 array to target. So we are left with sum of other elements.
            
            //when there are elements greater than 1 then sum of other elements can not be 0 or sum can not be              greater than top element because sum + x(any number>0) is pq.top().
            if(sum == 0 || sum >= pq.top()) return false;
            
            //if we delete all copies of sum from pq.top() we get an old element.
            int old = pq.top() % sum;
            
            //all old elements were > 0 so it can not be 0 unless sum is 1 (This is only possible if array has              only 2 elements)
            if(sum != 1 && old == 0) return false;
            
            pq.pop();  

            pq.push(old); 
            sum += old; 
        }
        
        //if all elements are 1 then return true
        return true;
    }
};
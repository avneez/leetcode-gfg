class Solution {
public:
    int minPartitions(string n) {
        int len = n.length();
        int maxi = 0;
        
        for(auto element : n)
        {
            // convert the string number into integer number by subtracting the ascii value.
            int digit = element - '0';
            // cout<<digit<<endl;
            maxi = max(maxi,digit);
        }
        
        return maxi;
    }
};
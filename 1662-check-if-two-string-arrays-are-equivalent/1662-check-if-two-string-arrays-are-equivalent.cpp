class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       int m=word1.size();
       int n=word2.size();
       string temp1="", temp2="";
        
       for(auto it:word1) temp1+=it;
       for(auto it2:word2) temp2+=it2;
       if(temp1==temp2) return true;
        return false;
    }
};
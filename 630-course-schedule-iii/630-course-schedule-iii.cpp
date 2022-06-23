class Solution {
public:
    bool static comp(vector<int> v1, vector<int> v2){
       return v1[1]<v2[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        priority_queue<int> mx;
        
        int dur=0;
        for(auto course: courses){
            mx.push(course[0]);
            dur+=course[0];
            if(dur>course[1]){
                dur-=mx.top();
                mx.pop();
            }
        }
        return mx.size();
    }
};
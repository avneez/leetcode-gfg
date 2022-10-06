class TimeMap {
public:
    map<pair<string,int>,string> mp1;
    map<string,set<int>> mp2;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp1[{key,timestamp}] = value;
        mp2[key].insert(-1*timestamp);
    }
    
    string get(string key, int timestamp) {
        auto it = mp2[key].lower_bound(-1*timestamp);
        if(*it < -1*timestamp) return "";
        else return mp1[{key,-*it}];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
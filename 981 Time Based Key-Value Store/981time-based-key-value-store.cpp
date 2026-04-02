class TimeMap {
public:
    map<int,map<string,string>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[timestamp][key]=value;
    }
    
    string get(string key, int timestamp) {
        auto ub=mp.upper_bound(timestamp);
        while(ub!=mp.begin()){
            --ub;
            if(ub->second.find(key)!=ub->second.end()){
                return ub->second[key];
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
class TimeMap {
public:
    map<string,map<int,string>> m;
    TimeMap(){}
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(m[key].count(timestamp)){
            return m[key][timestamp];            
        }else{
            while(m[key].count(timestamp)==0 && timestamp>=0)timestamp--;
            if(timestamp<0)return "";
            return m[key][timestamp];
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
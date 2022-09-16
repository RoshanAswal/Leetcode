class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> um;
    list<pair<int,int>> li;
    int cap=0;
    LRUCache(int capacity){cap=capacity;}
    int get(int key) {
        auto it=um.find(key);
        if(it!=um.end()){
            li.splice(li.begin(),li,um[key]);
            return um[key]->second;
        }else return -1;
    }
    void put(int key, int value) {
        auto it=um.find(key);
        if(it!=um.end()){
            li.splice(li.begin(),li,um[key]);
            um[key]->second=value;
            return;
        }
        if(um.size()==cap){
            int k=li.back().first;
            li.pop_back();
            um.erase(k);
        }
        li.emplace_front(key,value);
        um[key]=li.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
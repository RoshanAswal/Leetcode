class UndergroundSystem {
public:
    map<int,pair<string,int>> m;
    map<pair<string,string>,pair<double,int>> dis;
    UndergroundSystem() {
        //
    }
    
    void checkIn(int id, string stationName, int t) {
        m[id].first=stationName;
        m[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        dis[{m[id].first,stationName}].first+=(t-m[id].second);
        dis[{m[id].first,stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto it=dis.find({startStation,endStation});
        return it->second.first/it->second.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
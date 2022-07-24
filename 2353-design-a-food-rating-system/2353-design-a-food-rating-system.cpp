class FoodRatings {
public:
    map<string,map<string,int>> mtemp;
    map<string,set<pair<int,string>>> m;
    map<string,string> m1;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<cuisines.size();i++){
            m[cuisines[i]].insert({-ratings[i],foods[i]});
            mtemp[cuisines[i]].insert({foods[i],-ratings[i]});
            m1[foods[i]]=cuisines[i];
        }
    }
    void changeRating(string food, int newRating) {
        string c=m1[food];
        auto it=mtemp[c].find(food);
        auto itt=m[c].find({it->second,it->first});
        m[c].erase(itt);
        m[c].insert({-newRating,food});
        mtemp[c].erase(it);
        mtemp[c].insert({food,-newRating});
    }
    string highestRated(string cuisine) {
        return m[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
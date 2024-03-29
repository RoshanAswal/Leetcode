class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        for(int &i:tasks)m[i]++;
        int ans=0;
        for(auto &it:m){
            if(it.second<2)return -1;
            ans+=(it.second/3)+(it.second%3?1:0);
        }
        return ans;
    }
};
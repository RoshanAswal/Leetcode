class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++)
            p.push_back({growTime[i],plantTime[i]});
        sort(p.begin(),p.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,p[i].first)+p[i].second;
        }
        return ans;
    }
};
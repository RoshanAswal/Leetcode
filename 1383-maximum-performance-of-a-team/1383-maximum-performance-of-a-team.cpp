class Solution {
public:
    int mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({eff[i],speed[i]});
        sort(v.rbegin(),v.rend());
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0,res=0;
        for(auto &it:v){
            sum+=it.second;
            pq.push(it.second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            // long long temp=((sum%mod)*(it.first)%mod)%mod;
            res=max(res,sum*it.first);
        }
        return res%mod;
    }
};
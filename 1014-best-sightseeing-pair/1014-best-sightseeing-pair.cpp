class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int ans=0,s=v.size(),prev=0;
        for(int i=0;i<s;i++){
            ans=max(ans,prev+v[i]-i);
            prev=max(prev,v[i]+i);
        }
        return ans;
    }
};
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=0;
        for(int &i:nums)mx=max(i,mx);
        vector<int> dp(mx+1,0);
        for(int &i:nums)dp[i]+=i;
        for(int i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1],dp[i]+dp[i-2]);
        }
        return dp[dp.size()-1];
    }
};
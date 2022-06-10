class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // int mx=*max_element(nums.begin(),nums.end());
        vector<int> dp(2e4+2,0);
        for(int &i:nums)dp[i]+=i;
        for(int i=2;i<dp.size();i++){
            dp[i]=max(dp[i-1],dp[i]+dp[i-2]);
        }
        return dp.back();
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        memset(dp,0,sizeof(dp));
        dp[1]=nums[0];
        for(int i=2;i<=nums.size();i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        return dp[nums.size()];
    }
};
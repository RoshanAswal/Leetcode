class Solution {
public:
    int robber (vector<int> &dp,vector<int> &nums,int i){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(robber(dp,nums,i+1),robber(dp,nums,i+2)+nums[i]);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return robber(dp,nums,0);
    }
};
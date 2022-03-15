class Solution {
public:
    bool sol(int i,int t,vector<int>& nums,int sum,vector<vector<int>> &dp){
        if(i>=nums.size() || t>sum/2)return false;
        if(sum/2==t)return true;
        if(dp[i][t]!=-1)return dp[i][t];
        bool f=sol(i+1,t+nums[i],nums,sum,dp);
        bool s=sol(i+1,t,nums,sum,dp);
        if(f || s)
            dp[i][t]=true;
        else
            dp[i][t]=false;
        return dp[i][t];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum&1)return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return sol(0,0,nums,sum,dp);
    }
};
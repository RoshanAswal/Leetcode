class Solution {
public:
    bool sol(vector<int> &nums,int i,int sum,vector<int> &dp){
        if(sum==0)return true;
        if(sum<0 || i>=nums.size())return false;
        if(dp[sum]!=-1)return dp[sum];
        return dp[sum]=sol(nums,i+1,sum-nums[i],dp) || sol(nums,i+1,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,i=0;
        for(int &i:nums)sum+=i;
        if(sum&1)return false;
        vector<int> dp(sum/2+1,-1);
        return sol(nums,i,sum/2,dp);
    }
};
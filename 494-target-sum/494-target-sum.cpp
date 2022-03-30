class Solution {
public:
    map<pair<int,int>,int> dp;
    int sol(vector<int> &nums,int target,int n){
        if(n==0 && target==0)return 1;
        if(n==0)return 0;
        if(dp.count({n,target}))return dp[{n,target}];
        dp[{n,target}]=sol(nums,target+nums[n-1],n-1)+sol(nums,target-nums[n-1],n-1);
        return dp[{n,target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return sol(nums,target,nums.size());
    }
};
class Solution {
public:
    int dp[1001][1001];
    int sol(vector<int> &nums,int sum,int tar){
        if(sum==tar)return 1;
        if(sum>tar)return 0;
        if(dp[sum][tar]!=-1)return dp[sum][tar];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(tar>=nums[i]){
                ans+=sol(nums,sum+nums[i],tar);
            }
        }
        return dp[sum][tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return sol(nums,0,target);
    }
};
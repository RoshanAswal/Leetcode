class Solution {
public:
    int dp[1001];
    int sol(vector<int> &nums,int tar){
        if(tar==0)return 1;
        if(dp[tar]!=-1)return dp[tar];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=tar)
                ans+=sol(nums,tar-nums[i]);
        }
        return dp[tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return sol(nums,target);
    }
};
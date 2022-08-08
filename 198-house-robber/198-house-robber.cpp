class Solution {
public:
    int dp[401];
    int sol(vector<int> &nums,int ind){
        if(ind>=nums.size())return 0;
        if(dp[ind]!=-1)return dp[ind];
        int a=sol(nums,ind+1);
        int b=sol(nums,ind+2)+nums[ind];
        return dp[ind]=max(a,b);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return sol(nums,0);
    }
};
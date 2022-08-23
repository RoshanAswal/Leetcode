class Solution {
public:
    int dp[10001];
    bool sol(int i,vector<int> &nums){
        if(i>=nums.size())return false;
        if(i==nums.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=nums[i];j++){
            dp[i]=sol(i+j,nums);
            if(dp[i])return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return sol(0,nums);
    }
};
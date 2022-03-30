class Solution {
public:
    int dp[2501];
    Solution(){memset(dp,-1,sizeof dp);}
    int sol(int n,vector<int> &nums,int prev){
        if(n>=nums.size())return 0;
        if(dp[prev+1]!=-1)return dp[prev+1];
        int no=sol(n+1,nums,prev),yes=0;
        if(prev==-1 || nums[n]>nums[prev])
            yes=1+sol(n+1,nums,n);
        return dp[prev+1]=max(no,yes);
    }
    int lengthOfLIS(vector<int>& nums) {
        return sol(0,nums,-1);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        if(n==3)return max({nums[0],nums[1],nums[2]});
        dp[1]=nums[0];
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        int ans1=dp[n-1];
        memset(dp,0,sizeof(dp));
        dp[2]=nums[1];
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-2]+nums[i-1],dp[i-1]);
        }
        int ans2=dp[n];
        
        return max(ans1,ans2);
    }
};
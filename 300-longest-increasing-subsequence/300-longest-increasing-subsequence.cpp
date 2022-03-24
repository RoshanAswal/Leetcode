class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l=nums.size();
        int dp[l];
        memset(dp,0,l);
        dp[0]=1;
        for(int i=0;i<l;i++){
            int c=0;
            for(int j=0;j<i;j++){
                if(dp[j]==0)break;
                if(nums[j]<nums[i] && dp[j]>c)
                    c=dp[j];
            }
            dp[i]=c+1;
        }
        return *max_element(dp,dp+l);
    }
};
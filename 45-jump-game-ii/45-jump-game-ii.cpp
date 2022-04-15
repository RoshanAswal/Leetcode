class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        for(int i=0;i<n;i++)dp[i]=INT_MAX/2;
        dp[0]=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if((i-j)<=nums[j]){
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};
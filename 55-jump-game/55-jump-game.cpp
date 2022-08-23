class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && (i-j)<=nums[j]){
                    dp[i]=true;break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
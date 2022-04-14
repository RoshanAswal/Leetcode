class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=0;i<nums.size();i++)dp[i]=0;
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]==1 && (i-j)<=nums[j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
    // Just like subset sum if we find the half sum then it is guarantee that other half is present
        int sum=0;
        for(int i:nums)sum+=i;
        if(sum&1)return false;
        bool dp[nums.size()+1][sum/2+1];
        for(int i=0;i<=nums.size();i++)
            dp[i][0]=true;
        for(int i=1;i<=sum/2;i++)
            dp[0][i]=false;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=sum/2;j++){
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[nums.size()][sum/2];
    }
};
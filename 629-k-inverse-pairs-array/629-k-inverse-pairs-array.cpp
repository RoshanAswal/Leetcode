class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1001,vector<int>(1001));
        dp[0][0]=1;
        long long mod=1e9+7;
        for(int i=1;i<=n;i++){
            long long temp=0;
            for(int j=0;j<=k;j++){
                temp+=dp[i-1][j];
                if(j>=i)temp-=dp[i-1][j-i];
                dp[i][j]=((long long)dp[i][j]+temp)%mod;
            }
        }
        return dp[n][k];
    }
};
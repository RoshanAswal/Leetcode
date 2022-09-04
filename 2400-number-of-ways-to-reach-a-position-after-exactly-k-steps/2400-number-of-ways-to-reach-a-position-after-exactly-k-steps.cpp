int dp[5005][5005];
int mod=1e9+7;
class Solution {
public:
    int sol(int s,int e,int k){
        if(k==0)return s==e;
        if(dp[s][k]!=-1)return dp[s][k];
        long long ans=sol(s-1,e,k-1)%mod;
        ans=(ans+sol(s+1,e,k-1))%mod;
        return dp[s][k]=ans;
    }
    int numberOfWays(int s, int e, int k) {
        memset(dp,-1,sizeof(dp));
        return sol(s+2000,e+2000,k);
    }
};
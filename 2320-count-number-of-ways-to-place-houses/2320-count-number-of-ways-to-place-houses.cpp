class Solution {
public:
    int mod=1e9+7;
    int dp[10005][2];
    int sol(int i,int n,int prev){
        if(i==n)return 1;
        if(dp[i][prev]!=-1)
            return dp[i][prev];
        long long ans=0;
        if(!prev){
            ans+=sol(i+1,n,1);
            ans+=sol(i+1,n,0);
            ans=ans%mod;
        }else 
            ans+=sol(i+1,n,0);
        return dp[i][prev]=ans%mod;
    }
    int countHousePlacements(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=sol(0,n,0);
        return (1L*ans*ans)%mod;
    }
};
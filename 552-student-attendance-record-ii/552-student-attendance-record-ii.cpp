long long dp[100002][5][5];
class Solution {
public: 
    // 0 -P 
    //1 - L 
    //2 - A
    long long mod=1e9+7;
    int sol(long long n,int ab,int c=0){
        if(ab==2 || c==3)return 0;
        if(n==0)return 1;
        if(dp[n][ab][c]!=-1)
            return dp[n][ab][c];
        long long temp=0;
        temp=(temp%mod+sol(n-1,ab)%mod)%mod;
        temp=(temp%mod+sol(n-1,ab,c+1)%mod)%mod;
        temp=(temp%mod+sol(n-1,ab+1)%mod)%mod;
        dp[n][ab][c]=temp;
        return dp[n][ab][c];
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        return sol(n,0); 
    }
};
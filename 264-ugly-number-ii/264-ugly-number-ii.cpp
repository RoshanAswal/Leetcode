class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int> dp(n,0);
        dp[0]=1;
        int tw=0,th=0,fi=0;
        for(int i=1;i<n;i++){
            dp[i]=min({2*dp[tw],3*dp[th],5*dp[fi]});
            if(dp[i]==2*dp[tw])tw++;
            if(dp[i]==3*dp[th])th++;
            if(dp[i]==5*dp[fi])fi++;
        }
        return dp[n-1];
    }
};
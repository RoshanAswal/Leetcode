class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int prev=1,k=9;
        if(n==0)return prev;
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]*k+prev;
            prev+=dp[i-1];
            k--;
        }
        return dp[n];
    }
};
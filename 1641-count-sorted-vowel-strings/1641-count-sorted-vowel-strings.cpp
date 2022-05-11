class Solution {
public:
    int countVowelStrings(int n) {
        int dp[6][n+1];
        for(int i=1;i<6;i++)
            dp[i][1]=i;
        for(int i=1;i<n+1;i++)
            dp[1][i]=1;
        for(int i=2;i<6;i++){
            for(int j=2;j<n+1;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[5][n];
    }
};
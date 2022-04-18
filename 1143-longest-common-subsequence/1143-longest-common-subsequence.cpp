class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        for(int i=0;i<1001;i++)
            dp[i][0]=dp[0][i]=0;
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.length()][text2.length()];
    }
};
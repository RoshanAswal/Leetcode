class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n1=a.length(),n2=b.length();
        int dp[1001][1001];
        for(int i=0;i<1001;i++)dp[i][0]=dp[0][i]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
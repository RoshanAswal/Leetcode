class Solution {
public:
    int minDistance(string s, string t) {
        vector<vector<int>> dp(size(s)+1,vector<int>(size(t)+1,1));
        for(int i=0;i<=size(s);i++){
            for(int j=0;j<=size(t);j++){
                if(i==0 || j==0)dp[i][j]=i+j;
                else dp[i][j]=s[i-1]==t[j-1]?dp[i-1][j-1]:1+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[size(s)][size(t)];
    }
};
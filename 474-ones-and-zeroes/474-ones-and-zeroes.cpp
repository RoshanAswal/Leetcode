class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string &s:strs){
            int z=0,o=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='0')z++;
                if(s[i]=='1')o++;
            }
            for(int i=m;i>=z;i--){
                for(int j=n;j>=o;j--)
                    dp[i][j]=max(dp[i][j],dp[i-z][j-o]+1);
            }
        }
        return dp[m][n];
    }
};
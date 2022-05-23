class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        vector<vector<int>> v;
        int c=0;
        for(string &s:strs){
            int z=0,o=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='0')z++;
                if(s[i]=='1')o++;
            }
            v.push_back({z,o});
        }
        for(int i=0;i<l;i++){
            for(int j=m;j>=v[i][0];j--){
                for(int k=n;k>=v[i][1];k--){
                    dp[j][k]=max(dp[j][k],dp[j-v[i][0]][k-v[i][1]]+1);                        
                }
            }
        }
        return dp[m][n];
    }
};
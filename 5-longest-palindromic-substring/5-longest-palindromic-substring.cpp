class Solution {
public:
    string longestPalindrome(string &s) {
        if(s.length()<=1)
            return s;
        int dp[s.length()][s.length()];
        memset(dp,0,sizeof(dp));
        string ans="";
        ans+=s[0];
        for(int i=0;i<s.length();i++)
            dp[i][i]=1;
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j]){
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j]=1;
                        if(ans.size()<j-i+1){
                            ans=s.substr(i,j-i+1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
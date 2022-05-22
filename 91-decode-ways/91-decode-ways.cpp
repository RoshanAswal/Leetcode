class Solution {
public:
    int sol(string s,int i,int dp[]){
        if(i==s.length())return 1;
        if(dp[i])return dp[i];
        int ans=0;
        if(s[i]!='0')ans+=sol(s,i+1,dp);
        if(i+1<s.length() && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))ans+=sol(s,i+2,dp);
        dp[i]=ans;
        return dp[i];
    }
    int numDecodings(string s) {
        int dp[s.length()+1];
        for(int i=0;i<=s.length();i++)dp[i]=0;
        return sol(s,0,dp);
    }
};
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')return 0;
        int l=s.length();
        vector<int> dp(l+1,0);
        dp[0]=1;
        for(int i=1;i<s.length();i++){
            if(s[i]!='0')
                dp[i]+=dp[i-1];
            if(i-1>=0 && (s[i-1]=='1' || (s[i-1]=='2' && s[i]<='6'))){
                if(i-2<0)dp[i]++;
                else dp[i]+=dp[i-2];
            }
        }
        return dp[l-1];
    }
};
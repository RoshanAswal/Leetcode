class Solution {
public:
    int dp[1000005];
    int mod=1e9+7;
    int sol(int n,string &s){
        if(n==s.length())return 1;
        if(n>s.length())return 0;
        if(dp[n]!=-1)return dp[n];
        if(s[n]=='0')return 0;
        int ans=0;
        if(s[n]=='1'){
            ans=(ans+sol(n+1,s)%mod)%mod;
            if(n+1<s.length() && s[n+1]=='*'){
                for(int i=1;i<10;i++){
                    ans=(ans+sol(n+2,s)%mod)%mod;
                }
            }else ans=(ans+sol(n+2,s)%mod)%mod;
        }else if(s[n]=='2'){
            ans=(ans+sol(n+1,s)%mod)%mod;
            if(n+1<s.length() && s[n+1]=='*'){
                for(int i=1;i<7;i++){
                    ans=(ans+sol(n+2,s)%mod)%mod;
                }
            }else if(n+1<s.length() && s[n+1]<='6') ans=(ans+sol(n+2,s)%mod)%mod;
        }else if(s[n]=='*'){
                ans=(ans+sol(n+1,s)%mod)%mod;
                if(n+1<s.length() && s[n+1]=='*'){
                    for(int i=1;i<10;i++){
                        ans=(ans+sol(n+2,s)%mod)%mod;
                    }
                }else ans=(ans+sol(n+2,s)%mod)%mod;
                ans=(ans+sol(n+1,s)%mod)%mod;
                if(n+1<s.length() && s[n+1]=='*'){
                    for(int i=1;i<7;i++){
                        ans=(ans+sol(n+2,s)%mod)%mod;
                    }
                }else if(n+1<s.length() && s[n+1]<='6') ans=(ans+sol(n+2,s)%mod)%mod;
            for(int i=3;i<10;i++){
                ans=(ans+sol(n+1,s)%mod)%mod;
            }
        }else{
            ans=(ans+sol(n+1,s)%mod)%mod;
        }
        return dp[n]=ans%mod;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return sol(0,s);
    }
};
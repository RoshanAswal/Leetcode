class Solution {
public:
    int dp[2001];
    bool ispali(string &s,int l,int r){
        if(l>=r)return true;
        if(s[l]!=s[r])return false;
        return ispali(s,l+1,r-1);
    }
    int sol(string s,int i){
        if(i==s.length())return 0;
        if(dp[i]!=-1)return dp[i];
        string st;
        int ans=INT_MAX;
        for(int j=i;j<s.length();j++){
            st+=s[j];
            if(ispali(st,0,st.length()-1)){
                int cnt=sol(s,j+1)+1;
                ans=min(ans,cnt);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=sol(s,0);
        return ans-1;
    }
};
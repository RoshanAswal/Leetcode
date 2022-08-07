class Solution {
public:
    bool ispali(string &s,int l,int r){
        if(l>=r)return true;
        if(s[l]!=s[r])return false;
        return ispali(s,l+1,r-1);
    }
    int minCut(string s) {
        int dp[s.length()+1];
        memset(dp,0,sizeof(dp));
        for(int i=s.length()-1;i>=0;i--){
            int ans=INT_MAX;
            for(int j=i;j<s.length();j++){
                if(ispali(s,i,j)){
                    int cnt=dp[j+1]+1;
                    ans=min(ans,cnt);
                }
            }
            dp[i]=ans;
        }
        return dp[0]-1;
    }
};
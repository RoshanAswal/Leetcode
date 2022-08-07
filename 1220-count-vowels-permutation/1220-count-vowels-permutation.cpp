const int num=2e4+1;
int dp[27][num];
class Solution {
public:
    int mod=1e9+7;
    int sol(int n,char c){
        if(n==0)return 1;
        if(dp[c-'a'][n]!=-1)return dp[c-'a'][n];
        int ans=0;
        if(c=='e'){
            ans+=sol(n-1,'a');
            ans%=mod;
            ans+=sol(n-1,'i');
            ans%=mod;
        }
        if(c=='a'){
            ans+=sol(n-1,'e');
            ans%=mod;
            ans+=sol(n-1,'i');
            ans%=mod;
            ans+=sol(n-1,'u');
            ans%=mod;
        }
        if(c=='i'){
            ans+=sol(n-1,'e');
            ans%=mod;
            ans+=sol(n-1,'o');
            ans%=mod;
        }
        if(c=='o'){
            ans+=sol(n-1,'i');
            ans%=mod;
        }
        if(c=='u'){
            ans+=sol(n-1,'i');
            ans%=mod;
            ans+=sol(n-1,'o');
            ans%=mod;
        }
        return dp[c-'a'][n]=ans;
    }
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans+=sol(n-1,'a');
        ans%=mod;
        ans+=sol(n-1,'e');
        ans%=mod;
        ans+=sol(n-1,'i');
        ans%=mod;
        ans+=sol(n-1,'o');
        ans%=mod;
        ans+=sol(n-1,'u');
        ans%=mod;
        return ans;
    }
};
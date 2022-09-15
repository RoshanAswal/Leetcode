class Solution {
public:
    int dp[501][501];
    int solve(string word1,string word2,int l,int r){
        if(l<0 && r<0)return 0;
        if(l<0)return r+1;
        if(r<0)return l+1;
        if(dp[l][r]!=-1)return dp[l][r];
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        if(word1[l]!=word2[r]){
            a=solve(word1,word2,l-1,r);
            b=solve(word1,word2,l,r-1);
            c=solve(word1,word2,l-1,r-1);
            return dp[l][r]=min({a,b,c})+1;
        }else{
            return solve(word1,word2,l-1,r-1);
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,word1.length()-1,word2.length()-1);
    }
};
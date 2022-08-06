class Solution {
public:
    int dp[1001][1001];
    int sol(string &a,string &b,int i,int j){
        if(i-1==a.length() || j-1==b.length())return 0;
        if(dp[i][j])return dp[i][j];
        if(a[i-1]==b[j-1])
            dp[i][j]=sol(a,b,i+1,j+1)+1;
        else{
            dp[i][j]=max(sol(a,b,i+1,j),sol(a,b,i,j+1));
        }        
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,0,sizeof(dp));
        return sol(text1,text2,1,1);
    }
};
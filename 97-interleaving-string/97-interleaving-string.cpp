class Solution {
public:
    int dp[101][101][201];
    bool sol(string s1,string s2,string s3,int a,int b,int c){
        if(dp[a][b][c]!=-1)return dp[a][b][c];
        else if(c>=s3.length())return true;
        else if(a>=s1.length() && b>=s2.length())return false;
        bool b1=false,b2=false;
        if(a<s1.length() && s1[a]==s3[c])b1=sol(s1,s2,s3,a+1,b,c+1);
        if(b<s2.length() && s2[b]==s3[c])b2=sol(s1,s2,s3,a,b+1,c+1);
        return dp[a][b][c]=b1||b2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()<s2.length()+s1.length())return false;
        memset(dp,-1,sizeof(dp));
        return sol(s1,s2,s3,0,0,0);
    }
};
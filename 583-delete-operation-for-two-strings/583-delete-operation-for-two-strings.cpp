class Solution {
public:
    int sol(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(i==s.length() && j==t.length())return 0;
        if(i==s.length() || j==t.length())return max(s.length()-i,t.length()-j);
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==t[j])return sol(s,t,i+1,j+1,dp);
        return dp[i][j]=min(sol(s,t,i+1,j,dp),sol(s,t,i,j+1,dp))+1;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        return sol(word1,word2,0,0,dp);
    }
};
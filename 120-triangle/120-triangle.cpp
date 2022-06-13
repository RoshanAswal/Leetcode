class Solution {
public:
    int sol(vector<vector<int>> &t,int i,int j,vector<vector<int>> &dp){
        if(i==t.size()-1)return t[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        dp[i][j]=min(sol(t,i+1,j,dp),sol(t,i+1,j+1,dp))+t[i][j];
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return sol(t,0,0,dp);
    }
};
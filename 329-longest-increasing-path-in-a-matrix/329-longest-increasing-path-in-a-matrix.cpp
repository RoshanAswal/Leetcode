class Solution {
public:
    int dfs(int x,int y,vector<vector<int>> &m,int prev,vector<vector<int>> &dp){
        if(x<0 || y<0 || x>=m.size() || y>=m[0].size() || prev>=m[x][y])return 0;
        if(dp[x][y])return dp[x][y];
        int a=dfs(x+1,y,m,m[x][y],dp);
        int b=dfs(x,y+1,m,m[x][y],dp);
        int c=dfs(x-1,y,m,m[x][y],dp);
        int d=dfs(x,y-1,m,m[x][y],dp);
        return dp[x][y]=max({a,b,c,d})+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(i,j,matrix,-1,dp));
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long dp[51][51][51];
    long long mod=1e9+7;
    long long dfs(int m,int n,int move,int r,int c){
        if(r<0 || c<0 || r>=m || c>=n)return 1;
        if(dp[r][c][move]!=-1)return dp[r][c][move];
        if(move<=0)return 0;
        int a=dfs(m,n,move-1,r+1,c);
        int b=dfs(m,n,move-1,r-1,c);
        int d=dfs(m,n,move-1,r,c+1);
        int e=dfs(m,n,move-1,r,c-1);
        return dp[r][c][move]=(a%mod+b%mod+d%mod+e%mod)%mod;    
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove,startRow,startColumn);   
    }
};
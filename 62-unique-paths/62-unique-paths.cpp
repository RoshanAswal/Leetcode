class Solution {
public:
    int dp[101][101];
    // int sol(int m,int n,int i,int j){
    //     if(i<0 || j<0 || i>=m || j>=n)return 0;
    //     if(i==m-1 && j==n-1)return 1;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int a=sol(m,n,i+1,j);
    //     int b=sol(m,n,i,j+1);
    //     dp[i][j]=a+b;
    //     return dp[i][j];        
    // }
    int uniquePaths(int m, int n) {
        if(n==1 && m==1)return 1;
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]+=dp[i-1][j]+dp[i][j-1]+1;
            }
        }
        return dp[m-1][n-1]+1;
    }
};
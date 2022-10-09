class Solution {
public:
    vector<vector<vector<int>>> dp;
    const long long mod=1e9+7;
    int sol(vector<vector<int>> &grid,int &k,int n,int m,long long sum){
        sum%=k;
        if(n<0 || m<0)return 0;
        if(n==0 && m==0){
            sum+=grid[n][m];
            return (sum%k)==0;
        }
        if(dp[n][m][sum]!=-1)return dp[n][m][sum];
        long long temp=0;
        temp+=sol(grid,k,n-1,m,sum+grid[n][m]);
        temp%=mod;
        temp+=sol(grid,k,n,m-1,sum+grid[n][m]);
        temp%=mod;
        return dp[n][m][sum]=temp;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size()-1,m=grid[0].size()-1;
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return sol(grid,k,n,m,0);
    }
};
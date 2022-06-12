class Solution {
public:
    int sol(vector<vector<int>> &dp,vector<vector<int>> &grid,vector<vector<int>> &moveCast,int i,int j){
        if(i==grid.size()-1)return grid[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=INT_MAX;
        for(int k=0;k<moveCast[grid[i][j]].size();k++)
            mn=min(mn,grid[i][j]+moveCast[grid[i][j]][k]+sol(dp,grid,moveCast,i+1,k));
        return dp[i][j]=mn;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        vector<vector<int>> dp(51,vector<int>(51,-1));
        for(int i=0;i<grid[0].size();i++){
            int res=sol(dp,grid,moveCost,0,i);
            ans=min(ans,res);
        }
        return ans;
    }
};
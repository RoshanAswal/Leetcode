class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]==0)return;
        grid[i][j]=0;
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if((i==0 || j==0 || i==grid.size()-1 || j==grid[i].size()-1) && grid[i][j]==1)
                    dfs(i,j,grid);                    
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==1)ans++;
        }
        return ans;
    }
};
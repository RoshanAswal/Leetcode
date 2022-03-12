class Solution {
public:
    void sol(vector<vector<char>> &grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')
            return;
        grid[i][j]='2';
        sol(grid,i+1,j);
        sol(grid,i-1,j);
        sol(grid,i,j+1);
        sol(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    sol(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
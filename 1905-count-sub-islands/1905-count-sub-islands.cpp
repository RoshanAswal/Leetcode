class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid,vector<pair<int,int>> &temp){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return;
        grid[i][j]=0;
        temp.push_back({i,j});
        dfs(i+1,j,m,n,grid,temp);
        dfs(i-1,j,m,n,grid,temp);
        dfs(i,j+1,m,n,grid,temp);
        dfs(i,j-1,m,n,grid,temp);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<pair<int,int>>> sub;
        int m=grid2.size(),n=grid2[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1){
                    vector<pair<int,int>> temp;
                    dfs(i,j,m,n,grid2,temp);                    
                    sub.push_back(temp);
                }
            }
        }
        int ans=0;
        for(int i=0;i<sub.size();i++){
            int is=0;
            for(auto it:sub[i]){
                int x=it.first,y=it.second;
                if(grid1[x][y]==0){
                    is=1;break;
                }
            }
            if(!is)ans++;
        }
        return ans;
    }
};
class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>> &grid,queue<pair<int,int>> &q){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0 || grid[i][j]==2)return;
        grid[i][j]=2;
        q.push({i,j});
        dfs(i+1,j,m,n,grid,q);
        dfs(i-1,j,m,n,grid,q);
        dfs(i,j+1,m,n,grid,q);
        dfs(i,j-1,m,n,grid,q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dfs(i,j,m,n,grid,q);
                    break;
                }                
            }
            if(!q.empty())break;
        }
        int ans=INT_MAX;
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            int s=q.size();
            for(int j=0;j<s;j++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dir[i][0];
                    int yy=y+dir[i][1];
                    if(xx<0 || yy<0 || xx>=n || yy>=n) continue;
                    // cout<<grid[xx][yy]<<endl;
                    if(grid[xx][yy]==1){
                        return grid[x][y]-2;
                    }else if(grid[xx][yy]<grid[x][y]){
                        grid[xx][yy]=grid[x][y]+1;                            
                        q.push({xx,yy});
                    }
                }
            }
        }
        return ans;
    }
};
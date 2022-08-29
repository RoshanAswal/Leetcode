class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==1)continue;
                if(grid[i][j]=='0'){vis[i][j]=1;continue;}
                queue<pair<int,int>> q;
                q.push({i,j});
                while(!q.empty()){
                    int s=q.size();
                    for(int k=0;k<s;k++){
                        auto it=q.front();
                        q.pop();
                        int x=it.first,y=it.second;
                        if(vis[x][y]==1)continue;
                        vis[x][y]=1;
                        if(grid[x][y]=='0')continue;
                        if(x+1<row)q.push({x+1,y});
                        if(x-1>=0)q.push({x-1,y});
                        if(y+1<col)q.push({x,y+1});
                        if(y-1>=0)q.push({x,y-1});
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};
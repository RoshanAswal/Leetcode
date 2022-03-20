class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[m-1][n-1]==1 || grid[0][0]==1)return -1;
        vector<vector<int>> vis(m,vector<int>(n,1));
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> dir={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{1,1},{1,-1},{-1,1}};
        grid[0][0]=1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==m-1 && y==n-1)return grid[x][y];
            for(int i=0;i<8;i++){
                int xx=x+dir[i][0];
                int yy=y+dir[i][1];
                if(xx>=0 && yy>=0 && xx<m && yy<n && grid[xx][yy]==0){
                    q.push({xx,yy});
                    grid[xx][yy]=grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};
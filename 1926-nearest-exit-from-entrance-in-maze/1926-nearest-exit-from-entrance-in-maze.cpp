class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>> q;
        int i=entrance[0],j=entrance[1];
        int m=maze.size(),n=maze[0].size();
        
        int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        int vis[m][n],ans=0;
        
        memset(vis,0,sizeof(vis));
        q.push({i,j});
        while(!q.empty()){
            int s=q.size();
            for(int k=0;k<s;k++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(vis[x][y])continue;
                vis[x][y]=1;
                if((x==0 || y==0 || x==m-1 || y==n-1) && ans)return ans;
                for(int l=0;l<4;l++){
                    int xx=x+dir[l][0];
                    int yy=y+dir[l][1];
                    if(xx<m && yy<n && xx>=0 && yy>=0 && !vis[xx][yy] && maze[xx][yy]!='+')
                        q.push({xx,yy});
                }
            }
            ans++;
        }
        return -1;
    }
};
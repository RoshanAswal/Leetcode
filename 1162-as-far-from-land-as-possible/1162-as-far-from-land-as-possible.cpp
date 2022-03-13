class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int w=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    q.push({i,j});
            }
        }
        if(q.size()==m*n)return -1;
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        int ans=0;
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int xx=x+dir[i][0];
                    int yy=y+dir[i][1];
                    if(xx>=0 && yy>=0 && xx<m && yy<n && grid[xx][yy]==0){    
                        q.push({xx,yy}); 
                        grid[xx][yy]=1;
                    }
                }
            }
        }
        return --ans;
    }
};
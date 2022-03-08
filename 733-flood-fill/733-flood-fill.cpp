class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size(),m=image[0].size();
        
        int st=image[sr][sc];
        if(st==newColor) return image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        // map<pair<int,int>,int> vis;
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int s=q.size();
            for(int j=0;j<s;j++){
                int x=q.front().first,y=q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int xx=x+dir[i][0],yy=y+dir[i][1];
                    
                    if(xx>=0 && yy>=0 && xx<n && yy<m && image[xx][yy]==st){
                        image[xx][yy]=newColor;
                        q.push({xx,yy});
                        // vis[{xx,yy}]=1;
                    } 
                }
            }
        }
        return image;
    }
};
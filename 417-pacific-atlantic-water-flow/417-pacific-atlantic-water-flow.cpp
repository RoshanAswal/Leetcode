class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &vis,int prev){
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]<prev || vis[i][j]==1)return;
        vis[i][j]=1;
        dfs(i+1,j,mat,vis,mat[i][j]);
        dfs(i-1,j,mat,vis,mat[i][j]);
        dfs(i,j+1,mat,vis,mat[i][j]);
        dfs(i,j-1,mat,vis,mat[i][j]);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size(),col=heights[0].size();
        vector<vector<int>> l(row,vector<int>(col,0)),r(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            dfs(i,0,heights,l,-1);
            dfs(i,col-1,heights,r,-1);
        }
        for(int i=0;i<col;i++){
            dfs(0,i,heights,l,-1);
            dfs(row-1,i,heights,r,-1);
        }
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(l[i][j]==1 && r[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
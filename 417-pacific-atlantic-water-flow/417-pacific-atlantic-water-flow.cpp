class Solution {
public:
    void dfs(int i,int j,int m,int n,vector<vector<int>> &heights,vector<vector<int>> &v,int preval){
        if(i<0 || j<0 || i>=m || j>=n || heights[i][j]<preval || v[i][j]==1)return;
        v[i][j]=1;
        dfs(i+1,j,m,n,heights,v,heights[i][j]);
        dfs(i-1,j,m,n,heights,v,heights[i][j]);
        dfs(i,j+1,m,n,heights,v,heights[i][j]);
        dfs(i,j-1,m,n,heights,v,heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        if(n==0)return {};
        vector<vector<int>> P(m,vector<int>(n,0));
        vector<vector<int>> A(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            dfs(i,0,m,n,heights,P,-1);
            dfs(i,n-1,m,n,heights,A,-1);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,m,n,heights,P,-1);
            dfs(m-1,i,m,n,heights,A,-1);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(P[i][j]==1 && A[i][j]==1)
                    ans.push_back(vector<int>{i,j});
            }
        }
        return ans;
    }
};
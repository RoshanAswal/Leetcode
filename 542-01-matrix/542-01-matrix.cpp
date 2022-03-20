class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0)q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        vector<vector<int>> adder={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(i-1>=0 && mat[i-1][j]==-1){
                mat[i-1][j]=mat[i][j]+1;
                q.push({i-1,j});
            }
            if(i+1<n && mat[i+1][j]==-1){
                mat[i+1][j]=mat[i][j]+1;
                q.push({i+1,j});
            }
            if(j-1>=0 && mat[i][j-1]==-1){
                mat[i][j-1]=mat[i][j]+1;
                q.push({i,j-1});
            }
            if(j+1<m && mat[i][j+1]==-1){
                mat[i][j+1]=mat[i][j]+1;
                q.push({i,j+1});
            }
        }
        return mat;
    }
    
};
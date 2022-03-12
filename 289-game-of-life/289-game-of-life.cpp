class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                for(int k=0;k<8;k++){
                    int x=i+dir[k][0];
                    int y=j+dir[k][1];
                    if(x>=0 && x<n && y>=0 && y<m && board[x][y]==1)c++;
                }
                if(board[i][j]==1 && (c<2 || c>3))ans[i][j]=0;
                else if((board[i][j]==0 && c==3) || (board[i][j]==1 && c>1 && c<4))ans[i][j]=1;
            }
        }
        board=ans;
    }
};
class Solution {
public:
    vector<vector<string>> ans;
    bool canplace(int x,int y,vector<string> &vec,int n){
        for(int i=0;i<n;i++){
            if(vec[x][i]=='Q' || vec[i][y]=='Q')return false;
        }
        int r=x,c=y;
        while(r>=0 && c>=0){
            if(vec[r][c]=='Q')return false;
            r--;c--;
        }
        r=x,c=y;
        while(r<n && c<n){
            if(vec[r][c]=='Q')return false;
            r++;c++;
        }
        r=x,c=y;
        while(r<n && c>=0){
            if(vec[r][c]=='Q')return false;
            r++;c--;
        }
        r=x,c=y;
        while(r>=0 && c<n){
            if(vec[r][c]=='Q')return false;
            r--;c++;
        }
        return true;
    }
    void nqueen(int ind,vector<vector<string>> &chess,vector<string> &vec,int n){
        if(ind==n){
            chess.push_back(vec);
            return;
        }
        for(int j=0;j<n;j++){
            if(canplace(ind,j,vec,n)){
                vec[ind][j]='Q';
                nqueen(ind+1,chess,vec,n);
                vec[ind][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> chess;
        vector<string> vec;
        for(int i=0;i<n;i++){
            string s(n,'.');
            vec.push_back(s);
        }
        nqueen(0,chess,vec,n);
        return chess;
    }
};
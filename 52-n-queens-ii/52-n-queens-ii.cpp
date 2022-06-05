class Solution {
public:
    int ans=0;
    bool canplace(int x,int y,vector<string> &vec,int n){
        for(int i=0;i<n;i++){
            if(vec[x][i]=='Q' || vec[i][y]=='Q')return false;
        }
        int r=x,c=y;
        while(r<n && c<n){
            if(vec[r][c]=='Q')return false;
            r++;c++;
        }
        r=x,c=y;
        while(r>=0 && c>=0){
            if(vec[r][c]=='Q')return false;
            r--;c--;
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
    void nqueen(int ind,vector<string> &vec,int n){
        if(ind==n){
            ans++;return;
        }
        for(int j=0;j<n;j++){
            if(canplace(ind,j,vec,n)){
                vec[ind][j]='Q';
                nqueen(ind+1,vec,n);
                vec[ind][j]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> vec;
        for(int i=0;i<n;i++){
            string s(n,'.');
            vec.push_back(s);
        }
        nqueen(0,vec,n);
        return ans;
    }
};
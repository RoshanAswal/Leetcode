class Solution {
public:
    bool canMove(int i,int j,vector<string>& arr,int n){
        int row=i,col=j;
        while(row>=0 && col>=0){
            if(arr[row][col]=='Q')return false;
            row--;col--;
        }
        row=i,col=j;
        while(col>=0){
            if(arr[row][col]=='Q')return false;
            col--;
        }
        row=i,col=j;
        while(row<n && col>=0){
            if(arr[row][col]=='Q')return false;
            row++;col--;
        }
        return true;
    }
    void nqueen(int col,int n,vector<string>& temp,vector<vector<string>>& ans){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(canMove(i,col,temp,n)==true){
                temp[i][col]='Q';
                nqueen(col+1,n,temp,ans);
                temp[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> arr(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            arr[i]=s;
        nqueen(0,n,arr,ans);
        return ans;
    }
};
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int tar) {
        int row=mat.size(),col=mat[0].size();
        int arr[row+1][col+1];
        memset(arr,0,sizeof(arr));
        int ans=INT_MIN;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){   
                if(mat[i-1][j-1]==tar)return tar;
                else if(mat[i-1][j-1]<tar)ans=max(ans,mat[i-1][j-1]);
                arr[i][j]=(arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+mat[i-1][j-1]);
            }   
        }
        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                for(int k=i+1;k<=row;k++){
                    for(int l=j+1;l<=col;l++){
                        int temp=arr[k][l]-arr[k][j]-arr[i][l]+arr[i][j];
                        if(temp==tar)return tar;
                        else if(temp<tar)ans=max(ans,temp);
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        if(n==1 || m==1)return true;
        for(int j=m-2;j>=0;j--){
            int t=j+1;
            for(int i=1;i<n && t<m;i++){
                if(matrix[i][t]!=matrix[i-1][t-1])
                    return false;
                t++;
            }
        }
        for(int i=n-2;i>=0;i--){
            int t=i+1;
            for(int j=1;j<m && t<n;j++){
                if(matrix[t][j]!=matrix[t-1][j-1])
                    return false;
                t++;
            }
        }
        return true;
    }
};
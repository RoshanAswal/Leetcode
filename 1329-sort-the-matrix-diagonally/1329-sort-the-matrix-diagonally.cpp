class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int j=0;j<n;j++){
            int col=j,row=0;
            vector<int> temp;
            while(col<n && row<m)
                temp.push_back(mat[row++][col++]);
            sort(temp.begin(),temp.end());
            col=j,row=0;
            int ind=0;
            while(col<n && row<m){
                ans[row][col]=temp[ind++];
                col++;row++;
            }
        }
        for(int i=1;i<m;i++){
            int row=i,col=0;
            vector<int> temp;
            while(col<n && row<m)
                temp.push_back(mat[row++][col++]);
            sort(temp.begin(),temp.end());
            row=i,col=0;
            int ind=0;
            while(col<n && row<m){
                ans[row][col]=temp[ind++];
                col++;row++;
            }
        }
        return ans;
    }

};
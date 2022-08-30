class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        int row=matrix.size(),col=matrix[0].size();
        for(int j=0;j<col;j++){
            vector<int> ex;
            for(int i=row-1;i>=0;i--){
                ex.push_back(matrix[i][j]);
            }
            temp.push_back(ex);
        }
        matrix=temp;
    }
};
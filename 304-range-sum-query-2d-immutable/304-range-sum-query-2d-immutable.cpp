class NumMatrix {
public:
    vector<vector<int>> mati;
    NumMatrix(vector<vector<int>>& mat) {
        mati=mat;
        for(int i=0;i<mati.size();i++){
            for(int j=1;j<mati[0].size();j++){
                mati[i][j]+=mati[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0,r=row1;
        while(r<=row2){
            if(col1!=0)
                sum+=(mati[r][col2]-mati[r][col1-1]);
            else
                sum+=mati[r][col2];
            r++;
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
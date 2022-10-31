class Solution {
public:
    map<pair<int,int>,int> m;
    bool isToeplitzMatrix(vector<vector<int>>& matrix,int i=1,int j=1) {
    return (i>=matrix.size() || j>=matrix[0].size() || m.count({i,j}))?true:(matrix[i-1][j-1]==matrix[i][j])?(m[{i,j}]=(isToeplitzMatrix(matrix,i,j+1) && isToeplitzMatrix(matrix,i+1,j))):false; 
    }
};
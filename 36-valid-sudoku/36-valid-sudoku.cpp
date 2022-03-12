class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9),col(9),block(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int n=board[i][j]-'0';
                if(row[i].count(n) || col[j].count(n) || block[(i/3)*3+j/3].count(n))return false;
                row[i].insert(n);
                col[j].insert(n);
                block[(i/3)*3+j/3].insert(n);
            }
        }
        return true;
    }
};
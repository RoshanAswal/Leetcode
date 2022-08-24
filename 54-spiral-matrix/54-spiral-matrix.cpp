class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size()-1,n=mat[0].size()-1;
        int si=0,sj=0;
        int i=0,j=0;
        vector<int> ans;
        while(si<=m && sj<=n){
            while(j<=n)ans.push_back(mat[i][j++]);
            if(si>m || sj>n)break;
            j--;i++;si++;
            while(i<=m)ans.push_back(mat[i++][j]);
            if(si>m || sj>n)break;
            i--;j--;n--;
            while(j>=sj && j<=n)ans.push_back(mat[i][j--]);
            if(si>m || sj>n)break;
            j++;i--;m--;
            while(i>=si && i<=m)ans.push_back(mat[i--][j]);
            if(si>m || sj>n)break;
            i++;j++;sj++;
        }
        return ans;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),ind=-1,i=0;
        for(auto it:matrix){
            if(target>=it[0] && target<=it[n-1]){
                ind=i;break;
            }
            i++;
        }
        if(ind==-1)return false;
        int l=0,r=n-1;
        while(l<=r){
            int m=l+(r-l)/2;
            if(matrix[ind][m]==target)return true;
            else if(matrix[ind][m]>target)r=m-1;
            else l=m+1;
        }
        return false;
    }
};
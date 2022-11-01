class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> ans(m,-1);
        for(int b=0;b<m;b++){
            int i=0,j=b;
            while(i<n){
                if(grid[i][j]==1){
                    if(j+1>=m)break;
                    if(grid[i][j+1]!=grid[i][j])break;
                    j++;
                }else{
                    if(j-1<0)break;
                    if(grid[i][j-1]!=grid[i][j])break;
                    j--;
                }
                i++;
            }
            if(i>=n)ans[b]=j;
        }
        return ans;
    }
};
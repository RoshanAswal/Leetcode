class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<k;i++){
            int last=grid[m-1][n-1];
            for(int j=m-1;j>=0;j--){
                for(int l=n-1;l>=0;l--){
                    if(l!=0)
                        grid[j][l]=grid[j][l-1];
                    else{
                        if(j!=0)
                            grid[j][l]=grid[j-1][n-1];                        
                        else
                            grid[j][l]=last;
                    }
                }                
            }
        }
        return grid;
    }
};
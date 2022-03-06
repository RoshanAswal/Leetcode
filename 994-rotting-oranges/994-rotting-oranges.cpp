class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qq;
        
        int n= grid.size();
        int m= grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) qq.push({i,j});
            }
        }
        
        
        
    int ans=-1;
        
        
        
        while(qq.size()){
            
            int sz = qq.size();
            
            for(int i=0;i<sz;i++){
                
                pair<int,int> cur = qq.front(); qq.pop();
                int temp_i = cur.first;
                int temp_j = cur.second;
                
                if(temp_i + 1 <n && grid[temp_i+1][temp_j]==1){
                    grid[temp_i+1][temp_j]=2;
                    qq.push({temp_i+1,temp_j});
                }
                
                if(temp_j + 1 <m && grid[temp_i][temp_j+1]==1){
                    grid[temp_i][temp_j+1]=2;
                    qq.push({temp_i,temp_j+1});
                }
                
                if(temp_i-1>=0 && grid[temp_i-1][temp_j]==1){
                    grid[temp_i-1][temp_j]=2;
                    qq.push({temp_i-1,temp_j});
                }
                
                if(temp_j -1>=0 && grid[temp_i][temp_j-1]==1){
                    grid[temp_i][temp_j-1]=2;
                    qq.push({temp_i,temp_j-1});
                }
                
                
            }
         ans++;   
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return max(0,ans);
        
        
        
        
    }
};
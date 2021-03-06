int pref[104][104];
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int tar) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int i2=i;i2<=n;i2++){
                    for(int j2=j;j2<=m;j2++){
                        int val = pref[i2][j2] - pref[i2][j-1] +pref[i-1][j-1] - pref[i-1][j2];
                        if(val==tar) ans++;
                    }
                }
            }
        }
        return ans;
        
        
            
    }
};
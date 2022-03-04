class Solution {
public:
    double champagneTower(int poured, int qr, int qg) {
        vector<vector<double>> ans(100,vector<double>(100,0.0));
        vector<double> temp={double(poured)};
        ans.insert(ans.begin(),temp);
        for(int i=0;i<100;i++){
            for(int j=0;j<=i;j++){
                if(ans[i][j]>=1){
                    ans[i+1][j]+=(ans[i][j]-1)/2.0;
                    ans[i+1][j+1]+=(ans[i][j]-1)/2.0;
                    ans[i][j]=1;
                }
            }
        }
        return ans[qr][qg];
    }
};
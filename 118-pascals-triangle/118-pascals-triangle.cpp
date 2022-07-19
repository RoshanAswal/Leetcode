class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0]={1};
        int k=1;
        for(int i=1;i<n;i++){
            vector<int> temp;
            for(int j=0;j<=k;j++){
                if(j==0 || j==k)temp.push_back(1);
                else temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            ans[k]=temp;
            k++;
        }
        return ans;
    }
};
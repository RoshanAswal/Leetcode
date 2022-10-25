class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> temp;
        for(int i=1;i<n;i++){
            temp.clear();
            for(int j=0;j<=i;j++){
                int t=1;
                if(j>0 && j<i)
                    t=ans[i-1][j-1]+ans[i-1][j];
                temp.push_back(t);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& a, vector<vector<int>>& dig) {
        int c=0,ans=0;
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        for(int i=0;i<dig.size();i++){
            v[dig[i][0]][dig[i][1]]=1;
        }
        for(int i=0;i<a.size();i++){
            int flag=1;
            for(int j=a[i][0];j<=a[i][2];j++){
                for(int k=a[i][1];k<=a[i][3];k++){
                    if(!v[j][k]){
                        flag=0;
                        break;
                    }
                }
                if(!flag)break;
            }
            if(flag)ans++;
        }
        return ans;
    }
};
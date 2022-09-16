class Solution {
public:
    int dp[1005][1005];
    int sol(vector<int> &n,vector<int> &m,int l,int i){
        if(i>=m.size())return 0;
        if(dp[l][i]!=INT_MIN)return dp[l][i];
        int r=n.size()-1-i+l;
        dp[l][i]=max((m[i]*n[l])+sol(n,m,l+1,i+1),(m[i]*n[r])+sol(n,m,l,i+1));
        return dp[l][i];
    }
    int maximumScore(vector<int>& nums, vector<int>& m) {
        for(int i=0;i<1005;i++){
            for(int j=0;j<1005;j++){
                dp[i][j]=INT_MIN;
            }
        }
        return sol(nums,m,0,0);
    }
};
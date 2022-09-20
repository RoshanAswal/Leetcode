class Solution {
public:
    int ans=0;
    int dp[1001][1001];
    int sol(vector<int> &a,vector<int> &b,int i,int j){
        if(i==a.size() || j==b.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int temp=0;
        if(a[i]==b[j])temp=sol(a,b,i+1,j+1)+1;
        sol(a,b,i+1,j);
        sol(a,b,i,j+1);
        ans=max(ans,temp);
        return dp[i][j]=temp;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        sol(nums1,nums2,0,0);
        return ans;
    }
};
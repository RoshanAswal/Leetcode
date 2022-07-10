class Solution {
public:
    int dp[1001];
    int sol(vector<int> &cost,int ind){
        if(ind>=cost.size())return 0;
        if(dp[ind]!=0)return dp[ind];
        return dp[ind]=min(sol(cost,ind+1),sol(cost,ind+2))+cost[ind];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,sizeof(dp),0);
        return min(sol(cost,0),sol(cost,1));
    }
};
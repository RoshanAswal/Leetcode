class Solution {
public:
    int dp[1000001];
    bool sol(vector<int> &nums,int i){
        if(i>=nums.size())return true;
        if(dp[i]!=-1)return dp[i];
        bool ans=false;
        if(i+2<nums.size()){
            if(nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
                ans|=sol(nums,i+3);
        }
        if(i+1<nums.size()){
            if(nums[i]==nums[i+1])
                ans|=sol(nums,i+2);
        }
        if(i+2<nums.size()){
            if(nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
                ans|=sol(nums,i+3);
        }
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return sol(nums,0);
    }
};
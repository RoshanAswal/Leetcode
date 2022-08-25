class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<nums.size();i++)nums[i]+=nums[i-1];
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<target)break;
            int j=upper_bound(nums.begin(),nums.end(),nums[i]-target)-nums.begin();
            ans=min(ans,i-j+1);
        }
        return ans==INT_MAX?0:ans;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=1,sum=nums[0];
        int ans=INT_MAX;
        while(l<r){
            if(sum>=target){
                ans=min(ans,r-l);
                sum-=nums[l++];continue;
            }
            if(r<nums.size()){
                sum+=nums[r];
                r++;
            }else if(sum<target)break;
        }
        return ans==INT_MAX?0:ans;
    }
};
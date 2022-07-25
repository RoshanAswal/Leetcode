class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size(),ans=0;
        int l=0,r=n-1;
        for(int i=0;i<2;i++){
            while(l<r){
                ans=max(ans,min(nums[l],nums[r])*(r-l));
                if(nums[l]==nums[r]){
                    if(i==0)l++;
                    else r--;
                }else if(nums[l]>nums[r])r--;
                else l++;
            }            
        }
        return ans;
    }
};
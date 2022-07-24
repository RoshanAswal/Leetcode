class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1=nums[0],m2=nums[0],ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(m1,m2);
            m1=max(nums[i],m1*nums[i]);
            m2=min(nums[i],m2*nums[i]);
            ans=max(ans,m1);
        }
        return ans;
    }
};
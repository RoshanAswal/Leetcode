class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=1,z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)z++;
            else m*=nums[i];
        }
        vector<int> ans(nums.size(),0);
        if(z>1)return ans;
        for(int i=0;i<nums.size();i++){
            if(z){
                if(nums[i]==0)nums[i]=m;
                else nums[i]=0;
            }else nums[i]=m/nums[i];
        }
        return nums;
    }
};
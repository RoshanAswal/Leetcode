class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0],pre=0,suff=0;
        for(int i=0;i<nums.size();i++){
            pre=(pre?pre:1)*nums[i]; // calculating prefix sum
            suff=(suff?suff:1)*nums[nums.size()-i-1]; // calculating suffix sum
            ans=max({ans,pre,suff});
        }
        return ans;
    }
};
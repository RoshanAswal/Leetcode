class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,ans=nums.size();
        for(int i=0;i<nums.size();i++){
            nums[i]^=i;
            ans^=nums[i];
        }
        return ans;
    }
};
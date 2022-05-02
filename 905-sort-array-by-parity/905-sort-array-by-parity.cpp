class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0,r=1;
        while(l<r && r<nums.size()){
            while(l<r && !(nums[l]&1))l++;
            r=l+1;
            while(r<nums.size() && nums[r]&1)r++;
            if(l<r && r<nums.size())swap(nums[l],nums[r]);
        }
        return nums;
    }
};
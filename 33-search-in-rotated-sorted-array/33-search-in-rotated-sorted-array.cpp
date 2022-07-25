class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target<nums[m]){
                if(nums[r]<nums[m] && target<nums[l])l=m+1;
                else r=m-1;
            }else if(target>nums[m]){
                if(nums[m]<nums[l] && nums[r]<target)r=m-1;
                else l=m+1;
            }else return m;
        }
        return -1;
    }
};
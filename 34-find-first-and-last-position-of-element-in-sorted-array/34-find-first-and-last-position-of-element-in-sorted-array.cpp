class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,ind1=-1,ind2=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                ind1=m;
                r=m-1;
            }else if(nums[m]>target)r=m-1;
            else l=m+1;
        }
        l=0,r=nums.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target){
                ind2=m;
                l=m+1;
            }else if(nums[m]>target)r=m-1;
            else l=m+1;
        }
        return {ind1,ind2};
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            while(l<r && nums[l]==0)l++;
            while(l<r && nums[r]!=0)r--;
            if(l<r)swap(nums[l],nums[r]);
        }
        int i=0;
        while(i<n && nums[i]==0)i++;
        l=i,r=n-1;
        while(l<r){
            while(l<r && nums[l]==1)l++;
            while(l<r && nums[r]!=1)r--;
            if(l<r)swap(nums[l],nums[r]);
        }
    }
};
class Solution {
public:
    // int bin(int l,int r,vector<int> &nums,int target){
    //     while(l<r){
    //         int m=l+(r-l)/2;
    //         if(nums[m]==target)return m;
    //         else if(nums[m]>target)l=m+1;
    //         else r=m-1;
    //     }
    //     return -1;
    // }
    bool search(vector<int>& nums, int target) {
        // int min=*min_element(nums.begin(),nums.end());
        // int ind=0;
        // while(nums[ind]!=min)ind++;
        // int n=bin(0,ind+1,nums,target);
        // int m=bin(ind+1,nums.size(),nums,target);
        // if(m>=0 || n>=0)return true;
        // return false;
        for(int i:nums){
            if(target==i)return true;
        }
        return false;
    }
};
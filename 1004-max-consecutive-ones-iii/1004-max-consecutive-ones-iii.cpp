class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        while(r<nums.size()){
            if(nums[r]==1)r++;
            else if(k){
                k--;r++;
            }else{
                if(nums[l]!=1)k++;
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans;
    }
};
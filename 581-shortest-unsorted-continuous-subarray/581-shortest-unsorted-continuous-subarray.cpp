class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=0,r=nums.size()-1,m=nums[0],mi=INT_MAX;
        while(l<r && nums[l]<=nums[l+1])l++;
        while(r>0 && nums[r]>=nums[r-1])r--;
        for(int i=l;i<=r;i++){
            m=max(m,nums[i]);
            mi=min(mi,nums[i]);
        }
        for(int i=0;i<l;i++){
            if(nums[i]>mi){
                l=i;
            }
        }
        for(int j=r+1;j<nums.size();j++){
            if(nums[j]<m){
                r=j;
            }
        }
        if(l<r)return (r-l)+1;
        return 0;
    }
};
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<nums.size();i++)nums[i]+=nums[i-1];
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<target)break;
            int l=0,r=n;
            while(l<r){
                int m=(l+r)/2;
                if(nums[m]<=nums[i]-target){
                    l=m+1;
                }else r=m;
            }
            while(l>=0 && nums[l]<=nums[i]-target)l--;
            ans=min(ans,abs(i-l)+1);
        }
        return ans==INT_MAX?0:ans;
    }
};
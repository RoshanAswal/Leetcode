class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0,ans=0;
        vector<int> pre=nums;
        for(int i=1;i<pre.size();i++)
            pre[i]+=pre[i-1];
        map<int,int> m;
        while(r<nums.size()){
            if(m.find(nums[r])!=m.end() && m[nums[r]]>=l){
                l=m[nums[r]]+1;
            }
            m[nums[r]]=r;
            if(l==0)ans=max({ans,pre[r],nums[r]});
            else ans=max({ans,pre[r]-pre[l-1],nums[r]});
            r++;
        }
        return ans;
    }
};
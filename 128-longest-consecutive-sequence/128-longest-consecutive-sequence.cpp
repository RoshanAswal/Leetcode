class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int ans=1,temp=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1==nums[i])temp++;
            else if(nums[i-1]==nums[i]){}
            else temp=1;
            ans=max(temp,ans);
        }
        return ans;
    }
};
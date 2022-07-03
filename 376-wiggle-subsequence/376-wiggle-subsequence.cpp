class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int l=1,h=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]>0)h=l+1;
            else if(nums[i]-nums[i-1]<0)l=h+1;
        }
        return max(l,h);
    }
};
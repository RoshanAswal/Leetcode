class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c=0,mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(i>1 && nums[i-2]<=nums[i])nums[i-1]=nums[i-2];
                else if(i>1) nums[i]=mx+1;
                c++;
            }
            if(c>1)return false;
            mx=max(nums[i],mx);
        }
        return true;
    }
};
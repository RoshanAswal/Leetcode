class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=nums[0]+nums[1]+nums[nums.size()-1];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<target)l++;
                else r--;
                if(abs(sum-target)<abs(res-target))
                    res=sum;
            }
        }
        return res;
    }
};
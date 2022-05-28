class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.push_back(nums.size()+1);
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[abs(nums[i])]<0)ans.push_back(abs(nums[i]));
            nums[abs(nums[i])]*=-1;
        }
        return ans;
    }
};
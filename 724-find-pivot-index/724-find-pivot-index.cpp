class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> p1;
        int s=0,ans=nums.size();
        for(int i:nums){
            s+=i;
            p1.push_back(s);
        }
        s=0;
        for(int i=nums.size()-1;i>=0;i--){
            s+=nums[i];
            if(p1[i]==s)ans=min(i,ans);
        }
        if(ans<nums.size())
            return ans;
        return -1;
    }
};
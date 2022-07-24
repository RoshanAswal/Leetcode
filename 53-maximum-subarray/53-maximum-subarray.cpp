class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN/2,res=INT_MIN/2;
        for(int &i:nums){
            ans=max(i,ans+i);
            if(res<ans)res=ans;
        }
        return res;
    }
};
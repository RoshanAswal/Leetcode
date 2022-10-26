class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,ans=INT_MIN;
        for(int &i:nums){
            sum+=i;
            if(i>sum)sum=i;
            ans=max(ans,sum);
        }
        return ans;
    }
};
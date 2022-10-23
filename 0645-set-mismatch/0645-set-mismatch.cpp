class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(2);
        int n=nums.size(),num=1,i=0;
        while(i<n){
            if(nums[i]!=num){
                ans[1]=num;
            }
            int cnt=0;
            while(i<n && num==nums[i]){
                cnt++;i++;
            }
            if(cnt>1)ans[0]=num;
            num++;
        }
        if(ans[1]==0)ans[1]=n;
        return ans;
    }
};
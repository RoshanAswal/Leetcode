class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long avg=0,ans=0,ans1=0,ans2=0;
        for(int i:nums)avg+=i;
        avg/=nums.size();
        try{
            for(int i:nums){
                ans+=(abs(i-avg));  
                if(ans>INT_MAX)throw overflow_error("error");
            }          
        }catch(exception &e){ans=INT_MAX;}
        int m=nums.size()/2;
        for(int i:nums)ans1+=(abs(i-nums[m]));
        if(!(nums.size()&1) && m-1>=0){
            m--;
            for(int i:nums)ans2+=(abs(i-nums[m]));
        }else ans2=INT_MAX;
        return min({ans1,ans2,ans});
    }
};
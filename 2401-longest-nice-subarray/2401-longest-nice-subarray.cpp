class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        long long l=0,r=1,temp=nums[0],res=1;
        while(r<nums.size()){
            if((temp&nums[r])==0){
                temp|=nums[r];
                res=max(res,r-l+1);
            }else{
                temp=nums[r];
                for(int i=r-1;i>=l;i--){
                    if((nums[i]&nums[r])!=0){
                        l=i+1;break;
                    }
                    temp|=nums[i];
                }
            }
            r++;
        }
        return res;
    }
};
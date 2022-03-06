class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans=0;
        nums.push_back(0);
        nums.push_back(1010000000);
        sort(nums.begin(),nums.end());
        int i=1;
        long long one= 1;
        while(k && i<nums.size()){
            int diff=nums[i]-nums[i-1]-1;
            if(diff<=0) {i++;continue;}
            if(diff<=k){
                k-=diff;
                ans+=(one*nums[i]*(nums[i]-1))/2-(nums[i-1]*one*(nums[i-1]+1))/2;
            }else{
                ans+=((nums[i-1]+k)*one*(nums[i-1]+k+1))/2-(nums[i-1]*one*(nums[i-1]+1))/2;
                k=0;
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    int sol(int mid,vector<int>& nums,int m){
        int c=1,total=0;
        for(int i:nums){
            total+=i;
            if(total>mid){
                total=i;
                c++;
                if(c>m)return 0;
            }
        }
        return 1;
    }
    int splitArray(vector<int>& nums, int m) {
        int maxe=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i:nums)sum+=i;
        int l=maxe,r=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(sol(mid,nums,m))
                r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};
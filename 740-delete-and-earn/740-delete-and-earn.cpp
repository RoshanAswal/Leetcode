class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=1;i<=mx;i++)m[i]=0;
        for(int i=0;i<nums.size();i++)m[nums[i]]+=nums[i];
        int in=0,out=0;
        for(int j=1;j<=mx;j++){
            int i=out+m[j];
            int o=max(in,out);
            in=i;
            out=o;
        }
        return max(out,in);
    }
};
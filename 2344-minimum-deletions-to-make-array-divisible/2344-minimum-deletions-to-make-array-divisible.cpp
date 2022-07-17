class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
       int gcd=numsDivide[0],i=0;
        sort(nums.begin(),nums.end());
        for(int &i:numsDivide)gcd=__gcd(gcd,i);
        while(i<nums.size()){
            if(gcd%nums[i]==0)break;
            i++;
        }
        return i==nums.size()?-1:i;
    }
};
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int num1=0,num2=0;
        for(int &i:nums1)num1^=i;
        for(int &i:nums2)num2^=i;
        int l=nums1.size(),r=nums2.size();
        if(l&1 && r&1)return num1^num2;
        else if(l&1)return num2;
        else if(r&1)return num1;
        else return 0;
    }
};
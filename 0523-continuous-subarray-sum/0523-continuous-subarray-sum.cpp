class Solution {
public:
    bool checkSubarraySum(vector<int>& nums,int k) {
        int sum=0,prev=0;
        unordered_set<int> st;
        for(int &i:nums){
            sum+=i;
            int mod=sum%k;
            if(st.count(mod))return true;
            st.insert(prev);
            prev=mod;
        }
        return false;
    }
};
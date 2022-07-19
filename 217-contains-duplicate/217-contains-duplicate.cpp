class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int &i:nums)st.insert(i);
        return !(nums.size()==st.size());
    }
};
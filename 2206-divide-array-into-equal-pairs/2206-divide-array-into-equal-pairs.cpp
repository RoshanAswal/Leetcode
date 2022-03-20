class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int> m;
        for(int i:nums)
            m[i]++;
        for(auto it:m)
            if(it.second&1)return false;
        return true;
    }
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>,int> m;
        for(int i=0;i<nums.size();i++){
            int c=0;
            vector<int> temp;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p==0)c++;
                temp.push_back(nums[j]);
                if(c<=k)m[temp]++;
                else break;
            }
        }
        return m.size();
    }
};
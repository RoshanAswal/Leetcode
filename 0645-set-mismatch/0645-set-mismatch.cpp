class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans(2);
        for(int &i:nums){
            m[i]++;
            if(m[i]>1)ans[0]=i;
        }
        for(int i=1;i<nums.size();i++){
            if(m.count(i)==0){
                ans[1]=i;break;
            }
        }
        if(ans[1]==0)ans[1]=nums.size();
        return ans;
    }
};
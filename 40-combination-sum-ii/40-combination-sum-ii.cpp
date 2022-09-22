class Solution {
public:
    set<vector<int>> ans;
    void sol(vector<int> &nums,int tar,vector<int> temp,int i){
        if(!tar){
            ans.insert(temp);
            return;
        }
        for(int ind=i;ind<nums.size();ind++){
            if(nums[ind]>tar)return;
            if(ind>i && nums[ind]==nums[ind-1])continue;
            temp.push_back(nums[ind]);
            sol(nums,tar-nums[ind],temp,ind+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        sol(candidates,target,temp,0);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
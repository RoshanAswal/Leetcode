class Solution {
public:
    set<vector<int>> ans;
    void sol(vector<int> &nums,vector<int> &temp,vector<int> &vis){
        if(temp.size()==nums.size()){
            ans.insert(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i])continue;
            vis[i]=1;
            temp.push_back(nums[i]);
            sol(nums,temp,vis);
            vis[i]=0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        sol(nums,temp,vis);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};
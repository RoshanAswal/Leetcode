class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,vector<int>> m;
        sort(nums.begin(),nums.end());
        int prev=nums[0],c=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prev){
                m[c].push_back(prev);
                prev=nums[i];
                c=0;
            }
            c++;
        }
        m[c].push_back(prev);
        vector<int> ans;c=0;
        for(auto it=m.rbegin();it!=m.rend();it++){
            for(int i:it->second){
                c++;
                ans.push_back(i);
                if(c==k)return ans;
            }
        }
        return ans;
    }
};
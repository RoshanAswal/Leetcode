class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>> m;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto &it:m){
            vector<string> temp;
            for(int i=0;i<(it.second).size();i++)
                temp.push_back(strs[it.second[i]]);
            ans.push_back(temp);
        }
        return ans;
    }
};
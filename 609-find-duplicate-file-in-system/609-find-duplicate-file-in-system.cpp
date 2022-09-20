class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> um;
        vector<vector<string>> ans;
        for(int i=0;i<paths.size();i++){
            stringstream ss(paths[i]);
            string s,root;
            getline(ss,root,' ');
            while(getline(ss,s,' ')){
                string filename=root+'/'+s.substr(0,s.find('('));
                string content=s.substr(s.find('(')+1,s.find(')')-s.find('(')-1);
                um[content].push_back(filename);
            }
        }
        for(auto &it:um){
            if(it.second.size()>1)
                ans.push_back(it.second);
        }
        return ans;
    }
};
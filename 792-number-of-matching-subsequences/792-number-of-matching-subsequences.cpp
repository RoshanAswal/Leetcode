class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<const char*> wait[128];
        for(string &str:words)wait[str[0]].push_back(str.c_str());
        for(char &c:s){
            auto curr=wait[c];
            wait[c].clear();
            for(auto it:curr)wait[*(++it)].push_back(it);
        }
        return wait[0].size();
    }
};
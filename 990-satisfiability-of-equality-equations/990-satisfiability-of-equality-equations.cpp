class Solution {
public:
    bool dfs(map<char,set<int>> &m,map<char,int> &vis,char s,char d){
        if(!vis[s]){
            vis[s]++;
            for(auto &c:m[s]){
                if(!vis[c]){
                    if(c==d || dfs(m,vis,c,d))
                        return true;
                }
            }
        }
        return false;
    }
    bool equationsPossible(vector<string>& equations) {
        map<char,set<int>> m;
        for(string &s:equations){
            if(s[1]!='!'){
                m[s[0]].insert(s[3]);
                m[s[3]].insert(s[0]);
            }else{
                if(s[0]==s[3])return false;
            }
        }
        map<char,int> vis;
        for(string &s:equations){
            vis.clear();
            if(s[1]=='!'){
                if(dfs(m,vis,s[0],s[3]))return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        
        set<string> avl;
        for(string &s:wordList){
            avl.insert(s);
        }
        
        q.push(beginWord);
        int ans=0;
        map<string,int> vis;
        for(int i=0;i<wordList.size();i++)vis[wordList[i]]=0;
        string alpha="abcdefghijklmnopqrstuvwxyz";
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int i=0;i<s;i++){
                string cur = q.front(); q.pop();
                if(vis[cur]) continue;
                vis[cur]=1;
                if(cur==endWord) return ans;
                for(char &c:cur){
                    char temp = c;
                    for(char &c2:alpha){
                        c=c2;
                        if(avl.count(cur)){
                            q.push(cur);
                            avl.erase(cur);
                        }
                    }
                    c=temp;
                }
            }
        }
        return 0;
    }
};
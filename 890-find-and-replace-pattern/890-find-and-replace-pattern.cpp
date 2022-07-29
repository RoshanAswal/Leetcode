class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
        map<char,int> m;
        int i=0;
        string s;
        for(char &c:pat){
            if(m.find(c)==m.end()){
                m[c]=i;
                s+=(i+'0');
                i++;
            }else{
                s+=(m[c]+'0');
            }
        }
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            string t;
            int cnt=0;
            m.clear();
            for(char &c:words[i]){
                if(m.find(c)==m.end()){
                    m[c]=cnt;
                    t+=(cnt+'0');
                    cnt++;
                }else{
                    t+=(m[c]+'0');
                }
            }
            if(t==s)ans.push_back(words[i]);
        }
        return ans;
    }
};
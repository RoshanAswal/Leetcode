class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=words.size(),ans=0;
        map<char,vector<int>> m;
        for(int i=0;i<s.length();i++)m[s[i]].push_back(i);
        for(int i=0;i<n;i++){
            int ct=0,prev=-1;
            for(char &c:words[i]){
                int f=0;
                for(int j=0;j<m[c].size();j++){
                    if(m[c][j]>prev){
                        f++;ct++;
                        prev=m[c][j];
                        break;
                    }
                }
                if(f==0)break;
            }
            if(ct==words[i].length())ans++;
        }
        return ans;
    }
};
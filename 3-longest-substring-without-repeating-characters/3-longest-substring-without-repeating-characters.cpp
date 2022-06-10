class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,res=-1;
        map<char,int> m;
        string temp;
        while(r<s.length()){
            if(m.find(s[r])!=m.end() && m[s[r]]!=-1){
                while(l<=m[s[r]]){
                    m[s[l]]=-1;
                    l++;
                }
            }
            res=max(res,r-l+1);
            m[s[r]]=r;
            r++;
        }
        return res==-1?s.length():res;
    }
};
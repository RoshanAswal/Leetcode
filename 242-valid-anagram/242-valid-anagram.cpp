class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int s1=1,t1=1;
        for(int i=0;i<s.length();i++){
            s1+=(s[i])*((s[i]+1)/2);
            t1+=(t[i])*((t[i]+1)/2);
        }
        return s1==t1;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        map<char,int> m1,m2;
        for(char &c:s)m1[c]++;
        for(char &c:t)m2[c]++;
        if(m1.size()!=m2.size())return false;
        for(int i=0;i<s.length();i++){
            if(m1[s[i]]!=m2[s[i]])return false;
        }
        return true;
    }
};
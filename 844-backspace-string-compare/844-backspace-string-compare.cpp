class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string st,tt;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(st.size())st.erase(st.length()-1,1);
            }else{
                st+=s[i];
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(tt.size())tt.erase(tt.length()-1,1);
            }else{
                tt+=t[i];
            }
        }
        return st==tt;
    }
};
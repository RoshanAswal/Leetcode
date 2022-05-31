class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k)return false;
        set<string> st;
        int l=0,r=k-1;
        string temp=s.substr(0,k);
        st.insert(temp);
        while(r<s.length()-1){
            temp.erase(temp.begin());
            temp+=s[++r];
            st.insert(temp);
        }
        long long p=pow(2,k);
        return st.size()==p;
    }
};
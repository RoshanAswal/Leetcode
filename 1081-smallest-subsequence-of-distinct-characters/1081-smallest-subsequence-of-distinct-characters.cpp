class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> alpha(27,-1);
        string ans="";
        for(int i=0;i<s.length();i++)
                alpha[s[i]-'a']=i;
        stack<char> st;
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(m[s[i]]>0)continue;
            while(!st.empty() && st.top()>=s[i] && alpha[st.top()-'a']>i){
                m[st.top()]--;
                st.pop();
            }
            st.push(s[i]);
            m[s[i]]++;
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char,int> v;
        int prev[26]={0};
        for(int i=0;i<s.length();i++)
            prev[s[i]-'a']=i;
        string res="";
        for(int i=0;i<s.length();i++){
            if(v[s[i]-'a']>0)
                continue;
            while(!st.empty() && st.top()>=s[i] && prev[st.top()-'a']>i){
                v[st.top()-'a']--;
                st.pop();
            }
            st.push(s[i]);
            v[s[i]-'a']++;
        }
        while(!st.empty()){
            if(st.top()>='a' && st.top()<='z')
                res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
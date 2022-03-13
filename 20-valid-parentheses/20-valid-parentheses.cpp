class Solution {
public:
    bool isValid(string s) {
    if(s.length()<2)return false;
    int i=0;
    stack<char> st;
    while(s[i]!='\0')
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(!st.empty())
        {
            if(st.top()=='(' && s[i]==')')
                st.pop();
            else if(st.top()=='{' && s[i]=='}')
                st.pop();
            else if(st.top()=='[' && s[i]==']')
                st.pop();
            else
                return false;
        }else
            st.push(s[i]);
        i++;
    }
        if(st.empty())return true;
        else return false;
    }
};
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(ans);
                ans=0;
            }else{
                ans=st.top()+max(1,ans*2);
                st.pop();
            }
        }
        return ans;
    }
};
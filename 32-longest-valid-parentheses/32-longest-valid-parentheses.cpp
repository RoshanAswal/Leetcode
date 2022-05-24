class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0)
            return 0;
        int ans=0;
        for(int j=0;j<2;j++){
            int open=0,close=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='(')
                    open++;
                else if(s[i]==')')
                    close++;
                if(open==close)
                    ans=max(ans,open+close);
                else if((j==0 && open<close) || (j==1 && close<open))
                    open=close=0;
            }
            reverse(s.begin(),s.end());
        }
        return ans;
    }
};
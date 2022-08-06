class Solution {
public:
    int dp[301];
    bool sol(string &s,int ind,set<string> &st){
        if(ind==s.length())return true;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<s.length();i++){
            if(st.count(s.substr(ind,i-ind+1)) && sol(s,i+1,st)){
                dp[ind]=true;     
                return dp[ind];
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp,-1,sizeof(dp));
        for(string &s:wordDict)st.insert(s);
        return sol(s,0,st);
    }
};
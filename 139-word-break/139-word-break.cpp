class Solution {
public:
    map<string,int> dp;
    bool sol(string s,set<string> st){
        if(s.length()==0)return true;
        if(dp.find(s)!=dp.end())return dp[s];
        for(int i=1;i<=s.length();i++){
            string sub=s.substr(0,i);
            if(st.count(sub) && sol(s.substr(i),st)){
                dp[sub]=1;
                return dp[sub];
            }
        }
        dp[s]=0;
        return dp[s];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string str:wordDict)st.insert(str);
        return sol(s,st);
    }
};
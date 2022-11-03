class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int> m;
        for(string &s:words)
            m[s]++;
        int ans=0,odd=0;
        for(string &s:words){
            string t=s;
            swap(t[0],t[1]);
            if(s==t && m.count(s)){
                ans+=(m[s])*2;
                if(m[s]&1){
                    if(odd)ans-=2;
                    odd++;
                }
                m[s]=0;
            }else if(m.count(t) && m.count(s)){
                m[s]--;
                m[t]--;
                ans+=4;
            }
            if(m[s]<=0)m.erase(s);
            if(m[t]<=0)m.erase(t);
        }
        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int ans=0,prev=0,l=s.length();
        for(int i=0;i<l;i++){
            if(m.count(s[i])==0)m[s[i]]=i;
            else{
                ans=max(ans,i-prev);
                for(int j=prev;j<m[s[i]];j++)
                    m.erase(s[j]);
                prev=m[s[i]]+1;
                m[s[i]]=i;
            }
        }
        ans=max(l-prev,ans);
        if(ans==0)return s.length();
        return ans;
    }
};
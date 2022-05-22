class Solution {
public:
    int countSubstrings(string s) {
        int ans=s.length(),temp=0;
        for(int i=1;i<s.length()-1;i++){
            int l=i-1,r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                ans++;l--;r++;
            }
        }
        for(int i=0;i<s.length();i++){
            int l=i,r=i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                ans++;l--;r++;
            }
        }
        return ans;
    }
};
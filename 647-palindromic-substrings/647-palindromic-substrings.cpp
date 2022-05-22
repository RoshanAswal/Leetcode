class Solution {
public:
    int countSubstrings(string s) {
        int ans=s.length(),temp=0;
        if(s.length()==1)return 1;
        if(s.length()==2){
            if(s[0]==s[1])return 3;
            return 2;
        }
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
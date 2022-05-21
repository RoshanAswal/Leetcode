class Solution {
public:
    int characterReplacement(string s, int k2) {
        
        int ans=0;
        
        for(char c ='A';c<='Z';c++){
            int i=0;
            int last=0;
            int cnt=0;
            int k = k2;
            // cout<<c<<" ";
            while(i<s.size()){
                if(s[i]==c) {i++,cnt++;}
                else if(k) {k--,i++,cnt++;}
                else{
                   if(s[last]!=c) k++;
                    cnt--;
                    last++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
        
        
    }
};
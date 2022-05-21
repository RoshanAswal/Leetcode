class Solution {
public:
    int characterReplacement(string s, int k2) {
        
        int ans=0;
        
        for(char c ='A';c<='Z';c++){
            int i=0;
            int last=0;
            int k = k2;
            while(i<s.size()){
                if(s[i]==c) i++;
                else if(k) k--,i++;
                else{
                   if(s[last]!=c) k++;
                    last++;
                }
                ans=max(ans,i-last);
            }
        }
        return ans;
        
        
    }
};
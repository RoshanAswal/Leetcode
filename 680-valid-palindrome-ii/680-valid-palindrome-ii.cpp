class Solution {
public:
    bool validPalindrome(string s) {
        for(int i=0;i<2;i++){
            int l=0,r=s.length()-1,c=0;
            while(l<r){
                if(s[l]!=s[r]){
                    c++;
                    if(c>1)break;
                    l++;
                }else{
                    l++;r--;
                }
            }
            if(c<=1)return true;
            reverse(s.begin(),s.end());
        }
        return false;
    }
};
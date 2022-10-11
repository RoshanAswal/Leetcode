class Solution {
public:
    string breakPalindrome(string s) {
        int l=0,r=s.length()-1;
        if(l==r)return "";
        while(l<r){
            if(s[l]!='a' && s[r]!='a')break;
            l++;r--;
        }
        if(l>=r)s.back()++;   
        else s[l]='a';
        return s;
    }
};
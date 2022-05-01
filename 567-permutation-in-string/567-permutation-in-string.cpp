class Solution {
public:
    //Rabin Karp
    long mod=1e4+7;
    long code(string s,int l,int r){
        long d=0;
        for(int i=l;i<r;i++){
            d+=long(pow(3,s[i]-96));
        }
        return d;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())return false;
        int l=0,r=s1.length();
        long f=code(s1,l,r);
        while(r<=s2.length()){
            long s=code(s2,l,r);
            if(f==s)return true;
            l++;r++;
        }
        return false;
    }
};
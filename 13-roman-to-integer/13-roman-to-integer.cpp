class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int ans=0,i=0;
        for(i=1;i<s.length();i++){
            if(m[s[i-1]]<m[s[i]]){
                ans+=(m[s[i]]-m[s[i-1]]);
                i++;
            }else{
                ans+=m[s[i-1]];
            }
        }
        if(i==s.length())ans+=m[s[i-1]];
        return ans;
    }
};
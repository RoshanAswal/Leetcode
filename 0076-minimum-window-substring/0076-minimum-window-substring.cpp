class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> m1,m2;
        for(int i=0;i<t.length();i++)
            m1[t[i]]++;
        int requiredLength=t.length();
        int l=-1,r=-1,currLength=0;
        int len=s.length();
        string res=s+"extra";
        while(true){
            bool firstloop=false,secondloop=false;
           
            while(r<len-1 && currLength<requiredLength){
                r++;
                m2[s[r]]++;
                if(m2[s[r]]<=m1[s[r]])
                    currLength++;
                firstloop=true;
            }
            while(l<r && currLength==requiredLength){
                l++;
                string temp=s.substr(l,r-l+1);
                if(temp.length()<res.length())
                    res=temp;
                m2[s[l]]--;
                if(m2[s[l]]<m1[s[l]])
                    currLength--;
                secondloop=true;
            }
            if(firstloop==false && secondloop==false)
                break;
        }
        if(res.length()>len)
            return "";
        return res;
    }
};
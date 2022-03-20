class Solution {
public:
    long long maximumSubsequenceCount(string t, string p) {
        map<char,int> m; 
        int ind=0;
        for(int i=0;i<t.length();i++){
            if(t[i]==p[1] || t[i]==p[0])
                m[t[i]]++;
        }
        unsigned long long ans=0;
        if(m[p[0]]==0 && m[p[1]]==0)return 0;
        else if(m[p[0]]>0 && m[p[1]]==0)return m[p[0]];
        else if(m[p[1]]>0 && m[p[0]]==0)return m[p[1]];
        if(p[0]==p[1]){
            int n=m[p[0]]+1;
            for(int i=1;i<n;i++)
                ans+=i;
            return ans;
        }
        if(m[p[0]]>m[p[1]]){
            m[p[1]]++;
            t+=p[1];
        }else{
            m[p[0]]++;
            t=p[0]+t;
        }
        for(int i=0;i<t.length();i++){
            if(t[i]==p[0])
                ans+=m[p[1]];
            else if(t[i]==p[1])
                m[p[1]]--;
        }  
        return ans;
    }
};
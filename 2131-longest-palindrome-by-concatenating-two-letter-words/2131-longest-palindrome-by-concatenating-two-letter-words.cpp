class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> m;
        int l=words.size();
        int ans=0,f=0;
        for(string &s:words)m[s]++;
        for(int i=0;i<l;i++){
            if(m.count(words[i])==0)continue;
            if(words[i][0]==words[i][1]){
                int temp=m[words[i]];
                if(temp>1){
                    if(temp&1)temp--;
                    ans+=(temp*2);
                }
                if(m[words[i]]&1 && f==0){
                    ans+=2;f=1;
                }
                m.erase(words[i]);
            }else{
                string temp=words[i];
                reverse(temp.begin(),temp.end());
                if(m.count(temp)==0)continue;
                ans+=4;
                m[temp]--;m[words[i]]--;
                if(m[temp]==0)m.erase(temp);
                if(m[words[i]]==0)m.erase(words[i]);
            }
        }
        return ans;
    }
};
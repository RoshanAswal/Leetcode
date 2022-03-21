class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int> m;
        vector<int> v(26,-1);
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
            v[s[i]-'a']=i;
        }
        vector<int> ans;
        string temp="";
        int c=0;
        for(int i=0;i<s.length();i++){
            m[s[i]]--;
            temp+=s[i];
            if(m[s[i]]==0 && v[s[i]-'a']==i){
                int j=0;
                for(;j<temp.length();j++){
                    if(m[temp[j]]>=1)break;
                }
                if(j==temp.length()){
                    ans.push_back(temp.length());
                    // cout<<j<<" "<<temp<<endl;
                    temp="";
                }
            }
        }
        return ans;
    }
};
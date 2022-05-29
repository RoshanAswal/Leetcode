class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> st;
        for(int i=0;i<words.size();i++){
            vector<int> temp(26,0);
            int res=0;
            for(char &c:words[i])   temp[c-'a']+=1;
            for(int j=0;j<26;j++){
                if(temp[j]) res|=(1<<j);
            }
            st.push_back(res);
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            int l1=words[i].length();
            for(int j=i+1;j<words.size();j++){
                int l2=words[j].length();
                if((st[i]&st[j])==0)
                    ans=max(ans,l1*l2);
            }
        }
        return ans;
    }
};
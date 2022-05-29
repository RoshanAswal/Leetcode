class Solution {
public:
    bool check(int n,int m,vector<vector<int>> &st){
        for(int i=0;i<26;i++){
            if(st[n][i] && st[m][i])return false;
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        vector<vector<int>> st;
        for(int i=0;i<words.size();i++){
            vector<int> temp(26,0);
            for(char &c:words[i])
                temp[c-'a']=1;
            st.push_back(temp);
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            char c=words[i][0];
            int l1=words[i].length();
            for(int j=i+1;j<words.size();j++){
                int l2=words[j].length();
                if(check(i,j,st)){
                    ans=max(ans,l1*l2);
                }
            }
        }
        return ans;
    }
};
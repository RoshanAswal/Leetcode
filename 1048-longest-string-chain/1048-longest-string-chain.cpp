class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.length()<b.length();
        });
        int l=words.size();
        vector<int> dp(l+1,1);
        for(int i=1;i<l;i++){
            for(int j=0;j<i;j++){
                if(words[i].length()==words[j].length()+1){
                    int diff=0,l=0,r=0;
                    while(l<words[i].length() && r<words[j].length()){
                        if(words[i][l]==words[j][r]){l++;r++;}
                        else{diff++;l++;}
                        if(diff>1)break;
                    }
                    if(diff<=1)dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
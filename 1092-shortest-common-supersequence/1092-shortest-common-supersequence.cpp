class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int dp[1001][1001];
        for(int i=0;i<1001;i++)dp[i][0]=dp[0][i]=0;
        for(int i=1;i<=str1.length();i++){
            for(int j=1;j<=str2.length();j++){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans="";
        int n=str1.length(),m=str2.length();
        while(n>0 && m>0){
            if(str1[n-1]==str2[m-1]){
                ans+=str1[n-1];
                m--;n--;
            }else{
                if(dp[n-1][m]>dp[n][m-1])n--;
                else m--;
            }
        }
        reverse(ans.begin(),ans.end());
        int i=0,j=0,k=0;
        while(i<str1.length() || j<str2.length()){
            string sub=ans.substr(0,k);
            string sub1=ans.substr(k,ans.length()-k);
            if(i<str1.length() && str1[i]!=ans[k]){
                ans=sub+str1[i]+sub1;
                i++;
            }else if(j<str2.length() && str2[j]!=ans[k]){
                ans=sub+str2[j]+sub1;
                j++;
            }else{
                i++;j++;   
            }
            k++;
        }
        return ans;
    }
};
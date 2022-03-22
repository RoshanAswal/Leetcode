class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=1;i<=n;i++){
            int zz=0;
            for(int j=1;j<26;j++){
                if((n-i)*26>=k-j){
                    ans+=('a'+j-1);
                    k-=j;
                    zz=1;
                    break;
                }
            }
            if(zz==0){
                while(i++<=n)ans+='z';
            }
        }
        return ans;
    }
};
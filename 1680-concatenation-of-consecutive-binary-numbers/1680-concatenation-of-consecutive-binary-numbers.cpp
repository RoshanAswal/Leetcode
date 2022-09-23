class Solution {
public:
    int concatenatedBinary(int n) {
        int const mod=1e9+7;
        string ans;
        for(int i=1;i<=n;i++){
            string temp;
            int num=0;
            while((1<<num)<=i){
                int t=(i&(1<<num))?1:0;
                char c=(t+'0');
                temp+=c;
                num++;
            }
            reverse(temp.begin(),temp.end());
            ans+=temp;
        }
        // cout<<ans<<"\n";
        long long res=0,prev=1;
        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i]=='1'){
                res=(res+prev)%mod;
            }
            prev=(prev*2)%mod;
        }
        return res;
    }
};
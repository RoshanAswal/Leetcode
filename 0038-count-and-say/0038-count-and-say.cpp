class Solution {
public:
    string sol(string temp,int n,int num){
        if(num>=n)return temp;
        int i=0,l=temp.length();
        string ans;
        while(i<l){
            char c=temp[i];
            int cnt=0;
            while(i<l && temp[i]==c){
                i++;cnt++;
            }
            ans+=to_string(cnt);
            ans+=c;
        }
        return sol(ans,n,num+1);
    }
    string countAndSay(int n) {
        return sol("1",n,1);
    }
};
class Solution {
public:
    string sol(string temp,int n,int num){
        if(num>=n)return temp;
        vector<pair<char,int>> p;
        int i=0,l=temp.length();
        string ans;
        while(i<l){
            char c=temp[i];
            int cnt=0;
            while(i<l && temp[i]==c){
                i++;cnt++;
            }
            p.push_back({c,cnt});
        }
        for(int i=0;i<p.size();i++){
            ans+=to_string(p[i].second);
            ans+=p[i].first;
        }
        return sol(ans,n,num+1);
    }
    string countAndSay(int n) {
        if(n==1)return "1";
        return sol("1",n,1);
    }
};
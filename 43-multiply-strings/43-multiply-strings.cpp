class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        else if(num1=="1")return num2;
        else if(num2=="1")return num1;
        if(num1.length()>num2.length())swap(num1,num2);
        vector<vector<int>> v;
        int mx=0,prev=0,cnt=0;
        for(int i=num1.length()-1;i>=0;i--){
            vector<int> temp;
            prev=0;
            for(int i=0;i<cnt;i++)temp.push_back(0);
            for(int j=num2.length()-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0')+prev;
                temp.push_back(mul%10);
                if(mul>9){
                    mul/=10;prev=mul;
                }else prev=0;
            }
            if(prev)temp.push_back(prev);
            v.push_back(temp);
            mx=max(mx,int(temp.size())+cnt);
            cnt++;
        }
        for(int i=0;i<v.size();i++){
            if(v[i].size()<mx){
                while(v[i].size()!=mx)v[i].push_back(0);
            }
            reverse(v[i].begin(),v[i].end());
        }
        // for(int i=0;i<v.size();i++){
        //     for(int j=0;j<v[0].size();j++)cout<<v[i][j];
        //     cout<<endl;
        // }
        if(num1.length()==1){
            string s;
            for(int i=0;i<v[0].size();i++)s+=(v[0][i]+'0');
            return s;
        }
        prev=0;
        vector<int> res;
        for(int j=v[0].size()-1;j>=0;j--){
            int sum=0;
            for(int i=0;i<v.size();i++)sum+=v[i][j];
            sum+=prev;
            res.push_back(sum%10);
            if(sum/10)prev=sum/=10;
            else prev=0;
        }
        if(prev)res.push_back(prev);
        string result;
        for(int &i:res)result+=(i+'0');
        reverse(result.begin(),result.end());
        int ind=0;
        while(result[ind]=='0')ind++;
        return result.substr(ind);
    }
};
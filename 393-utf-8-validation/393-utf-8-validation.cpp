class Solution {
public:
    string bb(int i){
        string ans;
        while(i){
            if(i&1) ans+='1';
            else ans+='0';
            i>>=1;
        }
        while(ans.size()<8) ans.push_back('0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
    bool validUtf8(vector<int>& data) {
        vector<string> bin;
        for(int i:data){
            bin.push_back(bb(i));
        }
        for(int i=0;i<bin.size();i++){
            int c = 0;
            string &s = bin[i]; 
            while(c<8 && s[c]=='1') c++;
            if(c>=5 || c==1) return 0;
            if(c!=0){
                c--;
                if(i+c < bin.size()){
                    for(int j=1;j<=c;j++){
                        if(bin[i+j][0]=='1' && bin[i+j][1]=='0');
                        else return 0;
                    }
                    i+=c;
                }else return 0;     
            }
        }
        
        return 1;
    }
};
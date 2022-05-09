class Solution {
public:
    map<int,vector<char>> m;
    vector<string> ans;
    void sol(string d,string temp){
        if(d.length()==0){
            if(temp.size())ans.push_back(temp);
            return;
        }
        for(char &t:m[d[0]-'0']){
            string sub=d.substr(1,d.length()-1);
            sol(sub,temp+t);
        }
    }
    vector<string> letterCombinations(string digits) {
        char c='a';
        for(int i=2;i<=9;i++){
            int l=3;
            if(i==7 || i==9)l=4;
            for(int j=0;j<l;j++)
                m[i].push_back(c++);
        }
        string s;
        sol(digits,s);
        return ans;
    }
};
class Solution {
public:
    int isnum(string s){
        for(char &c:s){
            if(c=='-')continue;
            if(std::isdigit(c)==0)return false;            
        }
        return true;
    }
    int calPoints(vector<string>& ops) {
        vector<int> temp;
        for(int i=0;i<ops.size();i++){
            if(isnum(ops[i]))
                temp.push_back(stoi(ops[i]));
            else if(ops[i]=="C")
                temp.pop_back();
            else if(ops[i]=="D")
                temp.push_back(temp[temp.size()-1]*2);
            else if(ops[i]=="+")
                temp.push_back(temp[temp.size()-1]+temp[temp.size()-2]);
        }
        int sum=0;
        for(int i:temp)sum+=i;
        return sum;
    }
};
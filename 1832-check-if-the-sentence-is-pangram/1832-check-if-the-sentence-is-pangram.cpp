class Solution {
public:
    bool checkIfPangram(string s) {
        string temp="abcdefghijklmnopqrstuvwxyz";
        sort(s.begin(),s.end());
        s.erase(unique(s.begin(),s.end()),s.end());
        if(s.find(temp)==string::npos)return false;
        return true;
    }
};
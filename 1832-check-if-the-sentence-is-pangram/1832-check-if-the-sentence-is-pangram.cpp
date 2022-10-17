class Solution {
public:
    bool checkIfPangram(string s,char c='a') {
        return s.find(c)==string::npos?false:c=='z'?true:checkIfPangram(s,c+1);
    }
};
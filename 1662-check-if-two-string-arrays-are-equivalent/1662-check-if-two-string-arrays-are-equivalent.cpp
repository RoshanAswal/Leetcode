class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str,t;
        for(string &s:word1)str+=s;
        for(string &s:word2)t+=s;
        return str==t;
    }
};
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        if(s.length()<target.length())return 0;
        map<char,int> m1,m2;
        for(char &c:s)m1[c]++;
        for(char &c:target)m2[c]++;
        int ans=INT_MAX;
        for(auto it:m2){
            ans=min(ans,m1[it.first]/it.second);
        }
        return ans==INT_MAX?0:ans;
    }
};
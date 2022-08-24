class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string temp=strs[0];
        for(int i=1;i<strs.size();i++){
            int l=0,r=0;
            string temp2;
            while(l<strs[i].length() && strs[i][l]==temp[r]){temp2+=temp[r];l++;r++;}
            temp=temp2;                
        }
        return temp;
    }
};
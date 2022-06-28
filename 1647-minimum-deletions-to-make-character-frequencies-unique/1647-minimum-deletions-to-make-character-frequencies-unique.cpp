class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(char &c:s){
            freq[c-'a']++;
        }
        int ans=0;
        sort(freq.rbegin(),freq.rend());
        int prev=-1;
        for(int &i:freq){
            if(!i) break;
            if(prev==-1) prev = i;
            else{
                if(prev<=i){
                    ans+= i - max(0,(prev-1));
                    i = max(0,prev-1);
                }
            }
            prev=i;
        }
        return ans;
        
    }
};
class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int ans=0;
        string s="TF";
        for(char c:s){
            int l=0,r=0,t=k;
            while(r<a.length()){
                if(a[r]==c)r++;
                else if(t){
                    t--;r++;
                }else{
                    if(a[l]!=c)t++;
                    l++;
                }
                ans=max(ans,r-l);
            }
        }
        return ans;
    }
};
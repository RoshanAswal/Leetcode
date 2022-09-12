class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l=0,r=tokens.size()-1;
        int score=0,res=0;
        while(l<=r){
            if(power<tokens[l]){
                if(score==0)break;
                power+=tokens[r--];
                score--;
            }else{
                power-=tokens[l++];
                score++;
            }
            res=max(res,score);
        }
        return res;
    }
};
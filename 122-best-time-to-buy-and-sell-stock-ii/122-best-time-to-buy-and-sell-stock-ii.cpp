class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<int> curr(2,0),nxt(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            int b=nxt[1]-prices[i];
            int nb=nxt[0];
            int s=nxt[0]+prices[i];
            int ns=nxt[1];
            curr[0]=max(b,nb);
            curr[1]=max(s,ns);
            nxt=curr;
        }
        return curr[0];
    }
};
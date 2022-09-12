class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,mn=prices[0];
        for(int i=1;i<prices.size();i++){
            if(mn<prices[i])
                ans=max(ans,prices[i]-mn);
            mn=min(mn,prices[i]);
        }
        return ans;
    }
};
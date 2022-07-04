class Solution {
public:
    int candy(vector<int>& rat) {
        vector<int> ans(rat.size(),1);
        for(int i=1;i<rat.size();i++){
            if(rat[i]>rat[i-1])ans[i]=ans[i-1]+1;
        }
        for(int i=rat.size()-2;i>=0;i--){
            if(rat[i]>rat[i+1])ans[i]=max(ans[i],ans[i+1]+1);
        }
        int sum=0;
        for(int i:ans)sum+=i;
        return sum;
    }
};
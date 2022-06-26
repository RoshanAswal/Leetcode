class Solution {
public:
    int maxScore(vector<int>& cardP, int k) {
        int r=cardP.size()-k-1,l=0;
        for(int i=1;i<cardP.size();i++)
            cardP[i]+=cardP[i-1];
        int sum=cardP[cardP.size()-1];
        if(r<0)return sum;
        int ans=sum-cardP[r];
        r++;l++;
        while(r<cardP.size()){
            if(l==r)
                ans=max(ans,sum-(cardP[r]-cardP[r-1]));
            else
                ans=max(ans,sum-(cardP[r]-cardP[l-1]));
            l++;r++;
        }
        return ans;
    }
};
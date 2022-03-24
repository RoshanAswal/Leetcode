class Solution {
public:
    int numRescueBoats(vector<int>& p, int li) {
        sort(p.begin(),p.end());
        int s=p.size();
        int ans=0,temp=0;
        int r=s-1,l=0;
        while(r>l){
            if(p[l]+p[r]==li || p[l]+p[r]<li){
                l++;r--;
            }else{
                r--;
            }
            ans++;
        }
        if(l==r && p[l]<=li)ans++;
        return ans;
    }
};
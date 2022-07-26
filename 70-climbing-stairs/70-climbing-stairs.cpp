class Solution {
public:
    int climbStairs(int n) {
        int f=1,s=1,ans=1;
        for(int i=2;i<=n;i++){
            ans=f+s;
            f=s;
            s=ans;
        }
        return ans;
    }
};
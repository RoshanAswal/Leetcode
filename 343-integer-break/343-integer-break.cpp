class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n-1;
        int ans=pow(3,(n/3));
        if(n%3==2)ans*=2;
        if(n%3==1)ans=(ans/3)*4;
        return ans;
    }
};
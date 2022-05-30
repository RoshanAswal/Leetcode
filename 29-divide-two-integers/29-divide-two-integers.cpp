class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)return dividend;
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        int sign=1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))sign*=-1;
        long long a=labs(dividend),b=labs(divisor);
        int ans=0;
        while(a>=b){
            long long temp=b;
            int res=1;
            while((temp<<1)<=a){
                temp=temp<<1;
                res=res<<1;
            }
            ans+=res;
            a-=temp;
        }
        return ans*sign;
    }
};
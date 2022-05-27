class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)return dividend;
        if(dividend==INT_MIN && divisor==-1)return INT_MAX;
        long long ans=0,sign;
        if((dividend>0)^(divisor>0))
            sign=-1;
        else 
            sign=1;
        long long did=labs(dividend);
        long long div=labs(divisor);
        while(did>=div){
            long long temp=div,t=1;
            while((temp<<1)<=did){
                temp<<=1;
                t<<=1;
            }
            ans+=t;
            did-=temp;
        }
        return ans*sign;
    }
};
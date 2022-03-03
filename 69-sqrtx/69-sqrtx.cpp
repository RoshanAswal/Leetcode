class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        long long int prev=1,i=1;
        for(;i<=x/2+1;i++){
            if(i*i==x)return i;
            if(i*i>x)return prev;
            prev=i;
        }
        return (int)i;
    }
};
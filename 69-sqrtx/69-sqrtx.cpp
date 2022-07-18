class Solution {
public:
    int mySqrt(int x) {
        long long l=1,r=1e9;
        while(l<=r){
            long long m=l+(r-l)/2;
            long long sq=m*m;
            if(sq==x)return m;
            else if(sq>x)r=m-1;
            else l=m+1;
        }
        return r;
    }
};
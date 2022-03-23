class Solution {
public:
    int brokenCalc(int s, int t) {
        int c=0;
        while(s<t){
            if(t&1)t++;
            else t/=2;
            c++;
        }
        return c+s-t;
    }
};
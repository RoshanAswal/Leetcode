class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(!(p&1) && !(q&1)){
            p/=2;q/=2;
        }
        if(p&1){
            if(q&1)return 1;
            else return 0;
        }else
            return 2;
    }
};
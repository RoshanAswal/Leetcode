class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num){
            if(num&1){
                num--;ans++;
            }
            if(num){
                num/=2;ans++;
            }
        }
        return ans;
    }
};
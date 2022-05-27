class Solution {
public:
    int numberOfSteps(int num) {
        return num==0?0:__builtin_popcount(num)+log2(num);
    }
};
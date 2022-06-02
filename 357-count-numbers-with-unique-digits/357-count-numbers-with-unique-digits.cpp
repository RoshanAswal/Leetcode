class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        if(n==1)return 10;
        if(n==2)return 91;
        int k=3;
        int prev=91,prod=81,num=8,curr=91;
        while(k<=n){
            prod*=num;
            num--;
            prev=curr;
            curr+=prod;
            k++;
        }
        return curr;
    }
};
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> v;
        while(n){
            v.push_back(n%10);
            n/=10;
        }
        sort(v.begin(),v.end());
        do{
            int num=0,i=0;
            if(v[0]==0)continue;
            while(i<v.size()){
                num=num*10+v[i++];
            }
            if(!(num&(num-1)))return true;
        }while(next_permutation(v.begin(),v.end()));
        return false;
    }
};
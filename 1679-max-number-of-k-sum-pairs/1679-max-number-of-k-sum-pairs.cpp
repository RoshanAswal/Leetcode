class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> m;
        int c=0;
        for(int i:nums)m[i]++;
        for(int i:nums){
            if(m[i]>0 && m.find(k-i)!=m.end() && m[k-i]>0){
                if(i==k-i && m[i]==1){}
                else c++;
                m[i]--;m[k-i]--;
            }
        }
        return c;
    }
};
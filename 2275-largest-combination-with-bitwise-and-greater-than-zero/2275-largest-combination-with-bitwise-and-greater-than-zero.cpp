class Solution {
public:
    int largestCombination(vector<int>& c) {
        int ans=0;
        for(int i=0;i<32;i++){
            int ind=1<<i,ct=0;
            for(int i:c){
                if(i&ind)ct++;
            }
            ans=max(ans,ct);
        }
        return ans;
    }
};
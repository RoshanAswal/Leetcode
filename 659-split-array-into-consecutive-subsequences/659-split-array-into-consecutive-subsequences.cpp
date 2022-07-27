class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> remain,ends;
        for(int &i:nums)remain[i]++;
        for(int &i:nums){
            if(remain[i]>0){
                remain[i]--;
                if(ends[i-1]>0){
                    ends[i-1]--;
                    ends[i]++;
                }else if(remain[i+1]>0 && remain[i+2]>0){
                    remain[i+1]--;
                    remain[i+2]--;
                    ends[i+2]++;
                }else return false;
            }
        }
        return true;
    }
};
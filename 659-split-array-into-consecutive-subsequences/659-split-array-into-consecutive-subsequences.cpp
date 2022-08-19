class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> cnt,back;
        for(int &i:nums)cnt[i]++;
        for(int &i:nums){
            if(cnt[i]==0)continue;
            cnt[i]--;
            if(back[i-1]>0){
                back[i-1]--;back[i]++;
            }else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;cnt[i+2]--;
                back[i+2]++;
            }else return false;
        }
        return true;
    }
};
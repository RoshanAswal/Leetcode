class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        set<int> s;
        for(int i=0;i<nums.size();i++)s.insert(nums[i]);
        set<int>::iterator it=s.begin();
        int prev=*(it);
        it++;
        int temp=1,ans=1;
        while(it!=s.end()){
            if((*it)==prev+1)temp++;
            else if((*it)-prev>1)temp=1;
            ans=max(ans,temp);
            prev=*it;
            it++;
        }
        return ans;
    }
};
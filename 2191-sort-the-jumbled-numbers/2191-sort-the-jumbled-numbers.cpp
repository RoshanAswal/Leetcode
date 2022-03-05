class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<mapping.size();i++)
            m[mapping[i]]=mapping[mapping[i]];
        multimap<int,int> ans;
        for(int i=0;i<nums.size();i++){
            int temp=0,mul=1,dup=nums[i];
            if(nums[i]==0){
                temp=m[nums[i]];
            }else{
                while(nums[i]){
                    temp=(mul*m[nums[i]%10])+temp;
                    nums[i]/=10;
                    mul*=10;
                }                
            }
            ans.insert({temp,dup});
        }
        vector<int> res;
        for(auto it:ans){
            res.push_back(it.second);
        }
        return res;
    }
};
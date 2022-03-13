class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(k==0)return nums[0];
        if(nums.size()==1 && k&1)return -1;
        int ind=-1,m=-1;
        for(int i=0;i<=k;i++){
            if(i==nums.size())break;
            if(m<nums[i]){
                m=nums[i];
                ind=i;
            }
        }
        if(ind==k-1){
            int mm=-1;
            for(int i=0;i<=k;i++){
                if(i!=k-1)
                    mm=max(mm,nums[i]);
            }
            return mm;
        }else if(ind<k){
            return m;
        }else{
            m=-1;
            int i=0;
            for(int i=0;i<=k;i++)
                m=max(m,nums[i]);
            return m;    
        }
    }
};
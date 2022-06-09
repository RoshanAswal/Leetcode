class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        int l=0,r=num.size()-1;
        while(l<r){
            if(num[l]+num[r]==target)
                return {l+1,r+1};
            if(num[l]+num[r]>target)r--;
            else l++;
        }
        if(num[l]==target)return {l+1};
        if(num[r]==target)return {r+1};
        return {};
    }
};
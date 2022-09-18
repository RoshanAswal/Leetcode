class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        int l=0,r=height.size()-1,lm=0,rm=0,ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=lm)lm=height[l];
                else ans+=lm-height[l];
                l++;
            }else{
                if(height[r]>=rm)rm=height[r];
                else ans+=rm-height[r];
                r--;
            }
        }
        return ans;
    }
};
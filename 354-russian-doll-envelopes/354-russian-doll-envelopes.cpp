class Solution {
public:
    static bool cmp(vector<int>&a,vector<int> &b){
        return a[0]==b[0]?b[1]<a[1]:a[0]<b[0];
    }
    int LIS(vector<int> &temp){
        vector<int> ans;
        ans.push_back(temp[0]);
        for(int i=1;i<temp.size();i++){
            if(ans.size()==0 || ans.back()<temp[i])ans.push_back(temp[i]);
            else{
                int l=0,r=ans.size(),ind=0;
                while(l<r){
                    int m=l+(r-l)/2;
                    if(ans[m]<temp[i])l=m+1;
                    else{
                        ind=m;r=m;
                    }
                }
                ans[ind]=temp[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),cmp);
        vector<int> temp;
        for(int i=0;i<env.size();i++)
            temp.push_back(env[i][1]);
        return LIS(temp);
    }
};
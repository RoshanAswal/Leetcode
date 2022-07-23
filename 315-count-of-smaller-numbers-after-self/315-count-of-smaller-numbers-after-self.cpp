class Solution {
public:
    void merge(int s,int e,vector<pair<int,int>> &temp,vector<pair<int,int>> &ori,vector<int> &ans){
        int m=s+(e-s)/2;
        if(s<e){
            merge(s,m,temp,ori,ans);
            merge(m+1,e,temp,ori,ans);
        }
        int k=0,cnt=0;
        int l=s,r=m+1;
        while(l<=m && r<=e){
            if(ori[l]>ori[r]){
                temp[k++]=ori[r++];
                cnt++;
            }else if(ori[l]<ori[r]){
                ans[ori[l].second]+=cnt;
                temp[k++]=ori[l++];
            }else{
                r++;l++;
            }
        }
        while(l<=m){
            ans[ori[l].second]+=cnt;
            temp[k++]=ori[l++];
        }
        while(r<=e){
            temp[k++]=ori[r++];
        }
        k=0;
        for(int i=s;i<=e;i++)ori[i]=temp[k++];
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> temp,ori;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],i});
            ori.push_back({nums[i],i});
        }
        merge(0,n-1,temp,ori,ans);
        return ans;
    }
};